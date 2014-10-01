# $NetBSD: Makefile,v 1.1 2014/10/01 13:12:31 fhajny Exp $

DISTNAME=	v0.21.1
PKGNAME=	libgit2-${DISTNAME:S/v//1}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libgit2/libgit2/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libgit2.github.com/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

DIST_SUBDIR=	${PKGBASE}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libgit2.pc.in
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.21.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
