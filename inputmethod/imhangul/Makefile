# $NetBSD: Makefile,v 1.7 2004/08/11 22:16:54 minskim Exp $

DISTNAME=	imhangul-0.9.11
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://download.kldp.net/imhangul/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool
USE_PKGLOCALEDIR=	YES
GTK2_IMMODULES=		YES

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
