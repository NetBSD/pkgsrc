# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:18 wiz Exp $

DISTNAME=	imhangul-0.9.13
PKGREVISION=	1
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/2808/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool
USE_PKGLOCALEDIR=	YES
GTK2_IMMODULES=		YES

.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
