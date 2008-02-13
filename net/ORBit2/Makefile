# $NetBSD: Makefile,v 1.61 2008/02/13 19:36:48 drochner Exp $
#

DISTNAME=		ORBit2-2.14.12
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

PKG_OPTIONS_VAR=	PKG_OPTIONS.ORBit2
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=		-DINET6
.endif

PKGCONFIG_OVERRIDE=	ORBit-2.0.pc.in
PKGCONFIG_OVERRIDE+=	ORBit-CosNaming-2.0.pc.in
PKGCONFIG_OVERRIDE+=	ORBit-imodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	src/idl-compiler/ORBit-idl-2.0.pc.in

CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

PRINT_PLIST_AWK+=	/^@dirrm share\/idl$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

# needs interaction
#TEST_TARGRT=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
