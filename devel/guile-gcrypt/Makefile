# $NetBSD: Makefile,v 1.9 2023/02/08 21:39:54 nikita Exp $

DISTNAME=	guile-gcrypt-0.4.0
CATEGORIES=	devel
MASTER_SITES=	-https://notabug.org/cwebber/guile-gcrypt/archive/v${PKGVERSION_NOREV}.tar.gz

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

.include "../../lang/guile30/module.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
