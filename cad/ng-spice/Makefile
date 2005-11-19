# $NetBSD: Makefile,v 1.30 2005/11/19 20:38:30 dmcmahill Exp $
#

DISTNAME=	ng-spice-rework-17
PKGNAME=	ng-spice-17
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ngspice.sourceforge.net/
COMMENT=	Next generation circuit simulation program

WRKSRC=			${WRKDIR}/ng-spice-rework-17
USE_LIBTOOL=		YES
USE_MAKEINFO=		YES
USE_TOOLS+=		gmake
USE_GNU_READLINE=	uses rl_* interface

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-readline
LIBS+=			${BUILDLINK_LDADD.getopt}

INFO_FILES=	ngspice.info
TEXINFO_REQD=	4.6

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
