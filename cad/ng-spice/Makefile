# $NetBSD: Makefile,v 1.19 2003/09/28 09:13:55 jlam Exp $
#

DISTNAME=	ng-spice-rework-14
PKGNAME=	ng-spice-14
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ngspice.sourceforge.net
COMMENT=	Next generation circuit simulation program

CONFLICTS=	spice-[0-9]*

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
LIBS+=			${LIBGETOPT}

INFO_FILES=	ngspice.info

.include "../../devel/libgetopt/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
