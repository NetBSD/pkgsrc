# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=		boa-constructor-0.2.3.src
PKGNAME=		boaconstructor-0.2.3
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boa-constructor/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://boa-constructor.sourceforge.net/
COMMENT=		Python IDE

WRKSRC=		${WRKDIR}/boa-constructor-0.2.3
EXTRACT_CMD_OPTS.zip=	-aqo
PYTHON_VERSIONS_ACCEPTED=	23

BOADIR=	${PREFIX}/share/boa-constructor-0.2.3
SEDSUBST=	-e "s|@PYTHONBIN@|${PYTHONBIN}|"
SEDSUBST+=	-e "s|@PREFIX@|${PREFIX}|"

INSTALLATION_DIRS=	bin

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
