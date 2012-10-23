# $NetBSD: Makefile,v 1.5 2012/10/23 17:18:42 asau Exp $
#

DISTNAME=	nipper-cli-0.12.0
PKGNAME=	${DISTNAME:S/-cli//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nipper/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nipper.sourceforge.net/
COMMENT=	Performs security audits of network device configuration

USE_LANGUAGES=	c++ c
USE_CMAKE=	yes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	CMakeLists.txt nipper.cpp
SUBST_SED.config=	-e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_SED.config+=	-e "s|@@PKGMANDIR@@|${PKGMANDIR}|g"
SUBST_SED.config+=	-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.config=	Fixing configuration files.

.include "../../net/libnipper/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
