# $NetBSD: Makefile,v 1.55 2007/04/13 13:00:51 gdt Exp $
#

DISTNAME=		ORBit2-2.14.7
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit2/2.14/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		High-performance CORBA ORB with C language support

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		linc>=1.1

# make sometimes spins forever
MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
#TEST_TARGET=		check

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKGCONFIG_OVERRIDE=	ORBit-2.0.pc.in
PKGCONFIG_OVERRIDE+=	ORBit-CosNaming-2.0.pc.in
PKGCONFIG_OVERRIDE+=	ORBit-imodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	src/idl-compiler/ORBit-idl-2.0.pc.in

CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

PRINT_PLIST_AWK+=	/^@dirrm share\/idl$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
