# $NetBSD: Makefile,v 1.40 2005/08/07 19:47:23 tron Exp $

DISTNAME=	cscope-15.4
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		yacc lex

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--without-bison --with-flex

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
