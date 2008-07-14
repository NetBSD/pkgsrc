# $NetBSD: Makefile,v 1.19 2008/07/14 12:56:07 joerg Exp $

DISTNAME=	imhangul-0.9.13
PKGREVISION=	3
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/2808/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty
USE_PKGLOCALEDIR=	YES
GTK2_IMMODULES=		YES

.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
