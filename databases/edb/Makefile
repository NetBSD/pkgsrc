# $NetBSD: Makefile,v 1.1.1.1 2001/08/16 10:46:58 rh Exp $
#

DISTNAME=		edb-1.0.2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/pages/components.html
COMMENT=		database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
