# $NetBSD: Makefile,v 1.4 2015/06/03 13:14:46 taca Exp $

DISTNAME=	v0.22.2
PKGNAME=	libgit2-${DISTNAME:S/v//1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgit2/}
GITHUB_PROJECT=	libgit2
GITHUB_TAG=	v0.22.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libgit2.github.com/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

DIST_SUBDIR=	${PKGBASE}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

CMAKE_ARGS+=	-DUSE_SSH=OFF

PKGCONFIG_OVERRIDE+=	libgit2.pc.in
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.21.1

.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
