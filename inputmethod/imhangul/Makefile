# $NetBSD: Makefile,v 1.22 2011/04/24 14:11:08 obache Exp $

DISTNAME=	imhangul-0.9.14
PKGREVISION=	2
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/4944/
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

BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.9

.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
