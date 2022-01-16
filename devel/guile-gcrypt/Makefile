# $NetBSD: Makefile,v 1.6 2022/01/16 13:09:34 wiz Exp $

DISTNAME=	v0.3.0
DIST_SUBDIR=	guile-gcrypt
PKGNAME=	guile-gcrypt-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	https://notabug.org/cwebber/guile-gcrypt/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://notabug.org/cwebber/guile-gcrypt
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
