# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:01 wiz Exp $
#

VERSION=		0.4.4
DISTNAME=		boa-constructor-${VERSION}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boa-constructor/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://boa-constructor.sourceforge.net/
COMMENT=		Python IDE

EXTRACT_OPTS_ZIP=	-aqo
PYTHON_VERSIONS_ACCEPTED=	23 24

BOADIR=	${PREFIX}/share/boa-constructor-${VERSION}

SEDSUBST=	-e "s|@PYTHONBIN@|${PYTHONBIN}|"
SEDSUBST+=	-e "s|@PREFIX@|${PREFIX}|"
SEDSUBST+=	-e "s|@VERSION@|${VERSION}|"

INSTALLATION_DIRS=	bin

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

do-build:
	${SED} ${SEDSUBST} <${FILESDIR}/Boa.sh >${WRKDIR}/Boa

do-install:
	${MKDIR} ${BOADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${BOADIR}
	${CHMOD} -R go-w ${BOADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/Boa ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
