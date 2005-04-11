# $NetBSD: Makefile,v 1.9 2005/04/11 21:46:11 tv Exp $

DISTNAME=	imhangul-0.9.11
PKGREVISION=	1
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://download.kldp.net/imhangul/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool
USE_PKGLOCALEDIR=	YES
GTK2_IMMODULES=		YES

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
