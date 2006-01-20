# $NetBSD: Makefile,v 1.8 2006/01/20 23:41:29 jlam Exp $
#

VERSION=		0.4.4
DISTNAME=		boa-constructor-${VERSION}
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
