# $NetBSD: Makefile,v 1.36 2013/10/10 14:42:18 ryoon Exp $

DISTNAME=	imhangul-2.0.0
PKGREVISION=	12
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/5924/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/imhangul/
COMMENT=	GTK+-2.0 Hangul Input Module
LICENSE=	gnu-gpl-v2 # or later

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GTK2_IMMODULES=		YES
.include "../../x11/gtk2/modules.mk"

BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.12

.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
