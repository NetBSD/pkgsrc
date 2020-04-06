# $NetBSD: Makefile,v 1.6 2020/04/06 08:34:23 wiz Exp $

DISTNAME=	guile-git-0.2.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/guile-git/guile-git/uploads/160f6a36c1be8d4fc1990a193081a04d/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://gitlab.com/guile-git/guile-git/
COMMENT=	Guile bindings of libgit2
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
USE_TOOLS+=		pkg-config

DEPENDS+=		guile-bytestructures>=1.0.5:../../devel/guile-bytestructures

CONFIGURE_ENV+=		LIBGIT2_LIBDIR=${BUILDLINK_PREFIX.libgit2}/lib

INFO_FILES=	YES

.include "../../lang/guile22/module.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
