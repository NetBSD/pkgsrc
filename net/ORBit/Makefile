# $NetBSD: Makefile,v 1.74 2002/03/22 12:18:00 agc Exp $
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
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/popt/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		13
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

AUTOMAKE_OVERRIDE=	NO	# Otherwise breaks 1.5 arm32

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
