# $NetBSD: Makefile,v 1.2 2003/03/21 17:31:36 jmmv Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=	ezmlm-idx-0.40
PKGREVISION=	1
MASTER_SITES+=	http://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/ \
		ftp://ftp.ezmlm.org/pub/patches/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ezmlm.org/
COMMENT=	ezmlm with enhancements by third parties

CONFLICTS=	ezmlm-[0-9]*

DISTFILES+=	${EZMLM_VERS}.tar.gz
PLIST_SRC+=	PLIST.idx

USE_PKGINSTALL=	YES

PKG_SYSCONFSUBDIR=	ezmlm
CFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\"\\\"

EGDIR=		${PREFIX}/share/examples/ezmlm-idx
CONF_FILES=	${EGDIR}/ezcgirc ${PKG_SYSCONFDIR}/ezcgirc
CONF_FILES+=	${EGDIR}/ezmlmrc ${PKG_SYSCONFDIR}/ezmlmrc

pre-patch:
	@${MV} ${WRKSRC}/* ${WRKDIR}/${EZMLM_VERS}
	@${RMDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${EZMLM_VERS} ${WRKSRC}
	@cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < idx.patch

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ezcgirc ${EGDIR}/ezcgirc
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc ${EGDIR}/ezmlmrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmglrc ${EGDIR}/ezmlmglrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmsubrc ${EGDIR}/ezmlmsubrc

.include "../../mk/bsd.pkg.mk"
