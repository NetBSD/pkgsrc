# $NetBSD: Makefile,v 1.12 2023/10/24 22:08:45 wiz Exp $

DISTNAME=	guile-git-0.5.2
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=guile-git/}
GITLAB_PROJECT=	guile-git
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://gitlab.com/guile-git/guile-git/
COMMENT=	Guile bindings of libgit2
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
USE_TOOLS+=		pkg-config makeinfo

DEPENDS+=		guile-bytestructures>=1.0.5:../../devel/guile-bytestructures

CONFIGURE_ENV+=		LIBGIT2_LIBDIR=${BUILDLINK_PREFIX.libgit2}/lib

WRKSRC=		${WRKDIR}/guile-git-v0.5.2

INFO_FILES=	YES

.include "../../lang/guile30/module.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
