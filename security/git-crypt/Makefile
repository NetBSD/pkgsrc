# $NetBSD: Makefile,v 1.4 2023/10/24 22:10:47 wiz Exp $

DISTNAME=	git-crypt-0.7.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.agwa.name/projects/git-crypt/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.agwa.name/projects/git-crypt/
COMMENT=	Transparent file encryption in git
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

.include "../../security/openssl/buildlink3.mk"

# This isn't a header it needs, I'm just not sure of a better way to
# check for OpenSSL 3...
.if !exists(${SSLBASE}/include/openssl/rand_drbg.h)
CFLAGS+=	-DOPENSSL_API_COMPAT=0x30000000L
.endif

SUBST_CLASSES+=			explicit_memset
SUBST_STAGE.explicit_memset=	pre-configure
SUBST_MESSAGE.explicit_memset=	Avoid conflicts with explicit_memset(3)
SUBST_FILES.explicit_memset=	*.cpp *.hpp
SUBST_SED.explicit_memset+=	-e 's,explicit_memset,gitcrypt_explicit_memset,g'

.include "../../mk/bsd.pkg.mk"
