# $NetBSD: Makefile,v 1.77 2002/07/18 02:19:24 rh Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		gindent-[0-9]*:../../devel/gindent

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/popt/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libIDL/libtool

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		15
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

AUTOMAKE_OVERRIDE=	NO	# Otherwise breaks 1.5 arm32

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
