# $NetBSD: Makefile,v 1.106 2004/09/22 08:09:46 jlam Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit/0.${ORBIT_MAJOR}/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		High-performance CORBA ORB with support for the C language

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD" && ${OPSYS} != "Linux"
DEPENDS+=		gindent-[0-9]*:../../devel/gindent
.endif

USE_GNU_TOOLS+=		lex make yacc
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=	LIBWRAP_PATH=${BUILDLINK_PREFIX.tcp_wrappers}/lib/libwrap.a
CONFIGURE_ENV+=	LIB_WRAP="-lwrap"

PKGCONFIG_OVERRIDE+=	ORBit.pc.in
PKGCONFIG_OVERRIDE+=	libIDL/libIDL.pc.in

CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

# for DISTNAME, PKGNAME
ORBIT_MAJOR=		5
ORBIT_MINOR=		15

INFO_FILES=		libIDL.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
