# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:30 jlam Exp $
#

DISTNAME=		tvision-0.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

MAINTAINER=		packages@NetBSD.org
COMMENT=		Turbo Vision C++ CUI library for UNIX

DEPENDS+=		ncurses>=5.2:../../devel/ncurses

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
