# $NetBSD: Makefile,v 1.14 2003/05/02 11:55:58 wiz Exp $
#

DISTNAME=		ORBit2-2.6.0
PKGREVISION=	1
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit2/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		high-performance CORBA ORB with C language support

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/ORBit-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit-CosNaming-2.0.pc.in

.include "../../net/linc/buildlink2.mk"
.include "../../net/libIDL/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
