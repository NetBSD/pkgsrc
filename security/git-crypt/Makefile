# $NetBSD: Makefile,v 1.1 2022/12/05 21:57:58 nikita Exp $

DISTNAME=	git-crypt-0.7.0
CATEGORIES=	security
MASTER_SITES=	https://www.agwa.name/projects/git-crypt/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.agwa.name/projects/git-crypt/
COMMENT=	Transparent file encryption in git
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++11

SUBST_CLASSES+=			explicit_memset
SUBST_STAGE.explicit_memset=	pre-configure
SUBST_MESSAGE.explicit_memset=	Avoid conflicts with explicit_memset(3)
SUBST_FILES.explicit_memset=	*.cpp *.hpp
SUBST_SED.explicit_memset+=	-e 's,explicit_memset,gitcrypt_explicit_memset,g'

.include "../../mk/bsd.pkg.mk"
