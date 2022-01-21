# $NetBSD: Makefile,v 1.9 2022/01/21 17:09:29 nikita Exp $

DISTNAME=	guile-git-0.5.2
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/guile-git/guile-git/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://gitlab.com/guile-git/guile-git/
COMMENT=	Guile bindings of libgit2
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
USE_TOOLS+=		pkg-config makeinfo

DEPENDS+=		guile-bytestructures>=1.0.5:../../devel/guile-bytestructures

CONFIGURE_ENV+=		LIBGIT2_LIBDIR=${BUILDLINK_PREFIX.libgit2}/lib

WRKSRC=		${WRKDIR}/guile-git-v0.5.2-c5494ee3f7cdf891eb386f7103c86a962ab0ae62

INFO_FILES=	YES

.include "../../lang/guile22/module.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
