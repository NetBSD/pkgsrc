# $NetBSD: Makefile,v 1.70 2001/11/29 01:12:41 hubertf Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		gindent-[0-9]*:../../devel/gindent

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
ORBIT_MINOR=		8
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
