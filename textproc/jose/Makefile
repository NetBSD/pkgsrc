# $NetBSD: Makefile,v 1.4 2024/02/06 22:48:00 nikita Exp $

DISTNAME=	jose-12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=latchset/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latchset/jose/
COMMENT=	C implementation of JOSE
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config cmake

TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

post-install:
	${RM} -rf ${DESTDIR}/usr/pkg/share/licenses/jose

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
