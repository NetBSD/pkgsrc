# $NetBSD: Makefile,v 1.1 2017/11/05 03:53:12 tsutsui Exp $

DISTNAME=	cldr-emoji-annotation-31.90.0_1
PKGNAME=	${DISTNAME:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fujiwarat/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/fujiwarat/cldr-emoji-annotation
COMMENT=	Emoji annotation files in CLDR
LICENSE=	unicode

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoheader autoconf automake
USE_LANGUAGES+=	c

NO_BUILD=	YES	

do-configure:
	(cd ${WRKSRC} && ${SH} autogen.sh --prefix=${PREFIX})

.include "../../mk/bsd.pkg.mk"
