# $NetBSD: Makefile,v 1.24 2006/04/05 06:27:41 jlam Exp $
#

DISTNAME=	chicken-2.2
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INFO_FILES=	# PLIST
MAKE_FLAGS+=	MAKEINFO=${TRUE:Q}

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE:Q}

.include "../../mk/bsd.pkg.mk"
