# $NetBSD: Makefile,v 1.24 2004/12/02 13:33:32 dmcmahill Exp $
#

DISTNAME=	ng-spice-rework-15c
PKGNAME=	ng-spice-15c
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ngspice.sourceforge.net/
COMMENT=	Next generation circuit simulation program

CONFLICTS=	spice-[0-9]*

WRKSRC=			${WRKDIR}/ng-spice-rework-15
USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
USE_MAKEINFO=		YES
USE_GNU_TOOLS+=		make
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
