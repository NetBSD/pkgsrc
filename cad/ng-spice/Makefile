# $NetBSD: Makefile,v 1.12 2002/09/21 06:31:30 jlam Exp $
#

DISTNAME=	ng-spice-rework-14
PKGNAME=	ng-spice-14
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://ngspice.sourceforge.net
COMMENT=	Next generation circuit simulation program

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
LIBS+=			${LIBGETOPT}

.include "../../devel/libgetopt/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
