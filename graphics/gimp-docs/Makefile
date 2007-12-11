# $NetBSD: Makefile,v 1.8 2007/12/11 02:10:11 wulf Exp $

DISTNAME=	gimp-help-2.4.0
PKGNAME=	gimp-docs-2.4.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/help/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	Documentation package for The Gimp image manipulation software

DEPENDS+=       docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gimp

.include "../../mk/bsd.pkg.mk"
