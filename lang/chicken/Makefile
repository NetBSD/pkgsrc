# $NetBSD: Makefile,v 1.22 2006/02/05 23:09:43 joerg Exp $
#

DISTNAME=	chicken-2.2
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INFO_FILES=	chicken.info
MAKE_FLAGS+=	MAKEINFO=${TRUE:Q}

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE:Q}

.include "../../mk/bsd.pkg.mk"
