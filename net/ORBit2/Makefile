# $NetBSD: Makefile,v 1.25 2004/02/10 02:16:02 xtraeme Exp $
#

DISTNAME=		ORBit2-2.8.3
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit2/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		High-performance CORBA ORB with C language support

CONFLICTS=		linc>=1.1

USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PKGCONFIG_OVERRIDE=	${WRKSRC}/ORBit-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit-CosNaming-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit-imodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/idl-compiler/ORBit-idl-2.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
