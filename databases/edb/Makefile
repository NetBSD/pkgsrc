# $NetBSD: Makefile,v 1.6 2003/05/02 11:54:11 wiz Exp $
#

DISTNAME=		edb-1.0.3
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/pages/components.html
COMMENT=		database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
