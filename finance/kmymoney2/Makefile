# $NetBSD: Makefile,v 1.1.1.1 2003/05/05 12:46:30 markd Exp $

DISTNAME=	kmymoney2-0.5.1
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/kmymoney2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jnr@cwru.edu
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for kde3

USE_BUILDINK2=	YES
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
SHLIBTOOL_OVERRIDE=     ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-mt

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
