# $NetBSD: Makefile,v 1.49.4.1 2009/06/04 08:56:16 spz Exp $

DISTNAME=	cscope-15.7a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		byacc lex

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-flex --with-yacc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
