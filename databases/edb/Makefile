# $NetBSD: Makefile,v 1.3 2002/11/08 23:23:10 rh Exp $
#

DISTNAME=		edb-1.0.3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/pages/components.html
COMMENT=		database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
