# $NetBSD: Makefile,v 1.46 2020/04/06 08:33:40 wiz Exp $

DISTNAME=	libgit2-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgit2/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libgit2.org/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

EXTRACT_USING=	bsdtar
USE_CMAKE=	yes
USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DREGEX_BACKEND="pcre2"

PKGCONFIG_OVERRIDE+=	libgit2.pc.in

do-test:
	cd ${WRKSRC} && ctest

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
# for tests
.include "../../lang/python/pyversion.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
