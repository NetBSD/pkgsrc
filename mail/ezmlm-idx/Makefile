# $NetBSD: Makefile,v 1.32 2010/03/15 17:29:23 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		ezmlm-idx-${IDXVERSION}
IDXVERSION=		0.444
SITES.${DISTNAME}.tar.gz=	http://www.ezmlm.org/archive/${IDXVERSION}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.ezmlm.org/
COMMENT=		Version of ezmlm with enhancements by third parties
LICENSE=		public-domain

CONFLICTS=		ezmlm-[0-9]*

DISTFILES+=		${EZMLM_VERS}.tar.gz
PLIST_SRC+=		PLIST.idx

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DJB_RESTRICTED=		no
DJB_CONFIG_CMDS=	${ECHO} ${DESTDIR:Q} > conf-destdir

PKG_SYSCONFSUBDIR=	ezmlm
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
USE_TOOLS+=		patch

EGDIR=			${PREFIX}/share/examples/ezmlm-idx
CONF_FILES=		${EGDIR}/ezcgirc ${PKG_SYSCONFDIR}/ezcgirc
CONF_FILES+=		${EGDIR}/ezmlmrc ${PKG_SYSCONFDIR}/ezmlmrc

INSTALLATION_DIRS=	bin ${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1 ${PKGMANDIR}/cat5
INSTALLATION_DIRS+=	share/examples/ezmlm-idx

post-extract:
	${MV} ${WRKSRC}/* ${WRKDIR}/${EZMLM_VERS}
	${RMDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${EZMLM_VERS} ${WRKSRC}

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < idx.patch

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ezcgirc ${DESTDIR}${EGDIR}/ezcgirc
	${INSTALL_DATA} ${WRKSRC}/ezmlmrc ${DESTDIR}${EGDIR}/ezmlmrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmglrc ${DESTDIR}${EGDIR}/ezmlmglrc
	${INSTALL_DATA} ${WRKSRC}/ezmlmsubrc ${DESTDIR}${EGDIR}/ezmlmsubrc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
