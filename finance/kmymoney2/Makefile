# $NetBSD: Makefile,v 1.13 2004/04/26 02:44:47 snj Exp $

DISTNAME=	kmymoney2-0.5.1
PKGREVISION=	7
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/kmymoney2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jnr@cwru.edu
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for kde3

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
SHLIBTOOL_OVERRIDE=     libtool

CONFIGURE_ARGS+=	--enable-mt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
