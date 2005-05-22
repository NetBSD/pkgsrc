# $NetBSD: Makefile,v 1.27 2005/05/22 20:07:41 jlam Exp $
#

DISTNAME=	ng-spice-rework-15c
PKGNAME=	ng-spice-15c
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ngspice.sourceforge.net/
COMMENT=	Next generation circuit simulation program

WRKSRC=			${WRKDIR}/ng-spice-rework-15
USE_X11=		YES
USE_LIBTOOL=		YES
USE_MAKEINFO=		YES
USE_TOOLS+=		gmake
USE_GNU_READLINE=	uses rl_* interface

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-readline
LIBS+=			${LIBGETOPT}

INFO_FILES=	ngspice.info

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
