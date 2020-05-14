# $NetBSD: Makefile,v 1.8 2020/05/14 14:54:33 nikita Exp $

DISTNAME=	guile-git-0.3.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/guile-git/guile-git/uploads/4c563d8e7e1ff84396abe8ca7011bcaf/

MAINTAINER=	nikita@NetBSD.org
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
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
