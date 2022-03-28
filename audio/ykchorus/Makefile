# $NetBSD: Makefile,v 1.4 2022/03/28 10:43:41 tnn Exp $

DISTNAME=	ykchorus-v0.2.2-source
PKGNAME=	${DISTNAME:S/-source//1:S/-v/-/1}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=SpotlightKid/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SpotlightKid/ykchorus
COMMENT=	Chorus audio effect plugin
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ykchorus

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

# C++0x
GCC_REQD+=	4.7

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CXXFLAGS+=	-DDGL_FILE_BROWSER_DISABLED
.endif

# No CPU-specific optimizations
MAKE_FLAGS+=	NOOPT=true

REPLACE_SH+=	dpf/utils/generate-ttl.sh

.include "../../audio/jack/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
