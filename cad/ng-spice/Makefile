# $NetBSD: Makefile,v 1.37 2009/05/20 00:58:07 wiz Exp $
#

DISTNAME=	ng-spice-rework-17
PKGNAME=	ng-spice-17
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ngspice.sourceforge.net/
COMMENT=	Next generation circuit simulation program

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/ng-spice-rework-17
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake makeinfo
USE_GNU_READLINE=	uses rl_* interface

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-readline
LIBS+=			${BUILDLINK_LDADD.getopt}

INFO_FILES=	# PLIST
TEXINFO_REQD=	4.6

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
