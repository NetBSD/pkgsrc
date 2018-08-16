# $NetBSD: Makefile,v 1.27 2018/08/16 18:54:41 adam Exp $

DISTNAME=	libgit2-0.27.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgit2/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libgit2.github.com/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libgit2.pc.in

do-test:
	cd ${WRKSRC} && ctest

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
# for tests
.include "../../lang/python/pyversion.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
