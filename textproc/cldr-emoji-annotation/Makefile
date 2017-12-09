# $NetBSD: Makefile,v 1.3 2017/12/09 16:59:28 tsutsui Exp $

CLDREMJVER=	32.0.0_1
DISTNAME=	cldr-emoji-annotation-${CLDREMJVER}
PKGNAME=	${DISTNAME:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fujiwarat/}
GITHUB_PROJECT=	${DISTNAME:S/-${CLDREMJVER}//}
GITHUB_RELEASE=	${CLDREMJVER}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/fujiwarat/cldr-emoji-annotation
COMMENT=	Emoji annotation files in CLDR
LICENSE=	unicode

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoheader autoconf automake
USE_LANGUAGES+=	c
GNU_CONFIGURE=	yes

NO_BUILD=	YES	

.include "../../mk/bsd.pkg.mk"
