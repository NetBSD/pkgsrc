# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:43 jlam Exp $

DISTNAME=	imhangul-0.9.9
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://download.kldp.net/imhangul/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
GTK2_IMMODULES=		YES

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
