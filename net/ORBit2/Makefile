# $NetBSD: Makefile,v 1.22 2003/12/14 19:43:50 jmmv Exp $
#

DISTNAME=		ORBit2-2.8.2
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit2/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		High-performance CORBA ORB with C language support

CONFLICTS=		linc>=1.1

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PKGCONFIG_OVERRIDE=	${WRKSRC}/ORBit-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit-CosNaming-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit-imodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/idl-compiler/ORBit-idl-2.0.pc.in

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/libIDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
