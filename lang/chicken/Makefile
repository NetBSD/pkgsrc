# $NetBSD: Makefile,v 1.27 2006/11/03 19:24:26 joerg Exp $
#

DISTNAME=	chicken-2.41
CATEGORIES=	lang
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INFO_FILES=	yes
MAKE_FLAGS+=	MAKEINFO=${TRUE:Q}

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE:Q}

OWN_DIRS+=	${PREFIX}/lib/chicken
OWN_DIRS+=	${PREFIX}/lib/chicken/1

.include "../../mk/bsd.pkg.mk"
