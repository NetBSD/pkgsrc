# $NetBSD: Makefile,v 1.32 2004/02/14 00:59:28 grant Exp $
#

DISTNAME=	cscope-15.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		lex

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-flex
CONFIGURE_ENV+=		LEX=${LEX}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
