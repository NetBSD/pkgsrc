# $NetBSD: Makefile,v 1.41 2005/09/20 03:52:01 jlam Exp $

DISTNAME=	cscope-15.4
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		byacc lex

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-flex --with-yacc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
