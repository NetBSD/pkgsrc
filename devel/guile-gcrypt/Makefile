# $NetBSD: Makefile,v 1.1 2019/11/26 17:40:25 ng0 Exp $

DISTNAME=	v0.1.0
DIST_SUBDIR=	guile-gcrypt
PKGNAME=	guile-gcrypt-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	https://notabug.org/cwebber/guile-gcrypt/archive/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://notabug.org/cwebber/guile-gcrypt/archive/
COMMENT=	Guile bindings for libgcrypt
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/guile-gcrypt
USE_LANGUAGES=		# none
USE_TOOLS+=		pkg-config makeinfo
INFO_FILES=		yes
GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes

CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}

.include "../../lang/guile22/module.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
