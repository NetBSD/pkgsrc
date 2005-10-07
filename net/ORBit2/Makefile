# $NetBSD: Makefile,v 1.42 2005/10/07 16:03:21 drochner Exp $
#

DISTNAME=		ORBit2-2.12.4
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit2/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		High-performance CORBA ORB with C language support

PKG_INSTALLATION_TYPES= overwrite pkgviews

CONFLICTS=		linc>=1.1

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	ORBit-2.0.pc.in
PKGCONFIG_OVERRIDE+=	ORBit-CosNaming-2.0.pc.in
PKGCONFIG_OVERRIDE+=	ORBit-imodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	src/idl-compiler/ORBit-idl-2.0.pc.in

CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

PRINT_PLIST_AWK+=	/^@dirrm share\/idl$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
