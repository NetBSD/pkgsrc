# $NetBSD: Makefile,v 1.21 2005/09/30 15:02:55 wiz Exp $

DISTNAME=	kmymoney2-0.6.2
PKGREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmymoney2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for kde3

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=            YES
GNU_CONFIGURE=          YES
SHLIBTOOL_OVERRIDE=     libtool

CONFIGURE_ARGS+=	--enable-mt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
