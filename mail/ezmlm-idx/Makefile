# $NetBSD: Makefile,v 1.24 2005/09/02 01:08:48 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		ezmlm-idx-0.443
SITES_${DISTNAME}.tar.gz=	http://www.ezmlm.org/archive/${PKGVERSION}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.ezmlm.org/
COMMENT=		ezmlm with enhancements by third parties

CONFLICTS=		ezmlm-[0-9]*

DISTFILES+=		${EZMLM_VERS}.tar.gz
PLIST_SRC+=		PLIST.idx

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# ezmlm-idx is a modification of the ezmlm source.
DJB_RESTRICTED=		YES

USE_PKGINSTALL=		YES

PKG_SYSCONFSUBDIR=	ezmlm
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=			${PREFIX}/share/examples/ezmlm-idx
CONF_FILES=		${EGDIR}/ezcgirc ${PKG_SYSCONFDIR}/ezcgirc
CONF_FILES+=		${EGDIR}/ezmlmrc ${PKG_SYSCONFDIR}/ezmlmrc

INSTALLATION_DIRS=	bin man man/man1 man/man5 man/cat1 man/cat5
INSTALLATION_DIRS+=	share/examples/ezmlm-idx

post-extract:
	@${MV} ${WRKSRC}/* ${WRKDIR}/${EZMLM_VERS}
	@${RMDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${EZMLM_VERS} ${WRKSRC}

pre-patch:
	@cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < idx.patch

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ezcgirc ${EGDIR}/ezcgirc
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc ${EGDIR}/ezmlmrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmglrc ${EGDIR}/ezmlmglrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmsubrc ${EGDIR}/ezmlmsubrc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
