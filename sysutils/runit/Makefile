# $NetBSD: Makefile,v 1.1 2023/10/19 13:54:26 bsiegert Exp $

DISTNAME=	runit-2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/runit/
COMMENT=	UNIX init scheme with service supervision
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
PKGEXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}

USE_TOOLS+=		pax
BUILD_DEFS+=		VARBASE
DJB_SLASHPACKAGE=	YES

SERVICEDIR?=	${VARBASE}/spool/service
OWN_DIRS_PERMS=	${SERVICEDIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755

DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS package/TODO doc/*.html

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin"
SUBST_CLASSES+=		static
SUBST_STAGE.static=	pre-configure
SUBST_MESSAGE.static=	Disable static linking on SunOS
SUBST_FILES.static=	src/Makefile
SUBST_SED.static=	-e 's/-static//'
.endif

INSTALLATION_DIRS+=	${PKGMANDIR} ${PKGMANDIR}/man8 sbin share/examples/runit

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	cd ${WRKSRC}/etc && ${PAX} -rwppm . ${DESTDIR}${PKGEXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
