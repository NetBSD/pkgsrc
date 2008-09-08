# $NetBSD: Makefile,v 1.1.1.1 2008/09/08 17:27:56 adrianp Exp $
#

DISTNAME=	libnipper-0.12.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nipper/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://nipper.sourceforge.net/
COMMENT=	Performs security audits of network device configuration

USE_LANGUAGES=	c++
USE_CMAKE=	yes

CONF_FILES+=	${PREFIX}/share/examples/nipper.conf \
		${PKG_SYSCONFDIR}/nipper.conf

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	CMakeLists.txt libnipper.cpp nipper.cpp
SUBST_SED.config=	-e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_SED.config+=	-e "s|@@PKGMANDIR@@|${PKGMANDIR}|g"
SUBST_SED.config+=	-e "s|/etc|${PKG_SYSONFDIR}|g"
SUBST_MESSAGE.config=	Fixing configuration files.

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples
	${INSTALL_DATA} ${WRKSRC}/nipper.conf \
		${PREFIX}/share/examples/nipper.conf

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
