# $NetBSD: Makefile,v 1.81 2002/10/30 03:09:34 rh Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit/0.${ORBIT_MAJOR}/}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		gindent-[0-9]*:../../devel/gindent

AUTOMAKE_OVERRIDE=	NO	# Otherwise breaks 1.5 arm32
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/popt/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libIDL/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libIDL/libIDL.pc.in

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		15
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
