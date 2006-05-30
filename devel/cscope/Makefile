# $NetBSD: Makefile,v 1.43.2.1 2006/05/30 20:18:31 ghen Exp $

DISTNAME=	cscope-15.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		byacc lex

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-flex --with-yacc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
