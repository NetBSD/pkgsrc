# $NetBSD: Makefile,v 1.2 2001/05/17 08:38:44 abs Exp $
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
CONFIGURE_ENV+= 	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
