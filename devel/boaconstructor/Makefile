# $NetBSD: Makefile,v 1.14 2008/04/25 20:39:08 joerg Exp $
#

VERSION=		0.4.4
DISTNAME=		boa-constructor-${VERSION}
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boa-constructor/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://boa-constructor.sourceforge.net/
COMMENT=		Python IDE

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_OPTS_ZIP=	-aqo

BOADIR=	${PREFIX}/share/boa-constructor-${VERSION}

SEDSUBST=	-e "s|@PYTHONBIN@|${PYTHONBIN}|"
SEDSUBST+=	-e "s|@PREFIX@|${PREFIX}|"
SEDSUBST+=	-e "s|@VERSION@|${VERSION}|"

INSTALLATION_DIRS=	bin

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

do-build:
	${SED} ${SEDSUBST} <${FILESDIR}/Boa.sh >${WRKDIR}/Boa

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BOADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${BOADIR}
	${CHMOD} -R go-w ${DESTDIR}${BOADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/Boa ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
