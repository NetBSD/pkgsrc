# $NetBSD: Makefile,v 1.10 2002/01/26 02:38:30 dmcmahill Exp $
#

DISTNAME=	ng-spice-rework-14
PKGNAME=	ng-spice-14
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://ngspice.sourceforge.net
COMMENT=	Next generation circuit simulation program

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
LIBS+=			${LIBGETOPT}

USE_BUILDLINK_ONLY=	YES

.include "../../devel/libgetopt/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
