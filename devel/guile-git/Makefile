# $NetBSD: Makefile,v 1.13 2025/09/22 09:13:53 adam Exp $

DISTNAME=	guile-git-0.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=guile-git/}
GITLAB_PROJECT=	guile-git
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://gitlab.com/guile-git/guile-git/
COMMENT=	Guile bindings of libgit2
LICENSE=	gnu-gpl-v3

DEPENDS+=	guile-bytestructures>=1.0.5:../../devel/guile-bytestructures

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}

USE_TOOLS+=		pkg-config makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBGIT2_LIBDIR=${BUILDLINK_PREFIX.libgit2}/lib
GUILE_NEED_BOOTSTRAP=	yes

INFO_FILES=	yes

.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/guile30/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
