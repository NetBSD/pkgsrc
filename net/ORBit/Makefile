# $NetBSD: Makefile,v 1.94 2003/09/26 10:59:16 gavan Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit/0.${ORBIT_MAJOR}/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		High-performance CORBA ORB with support for the C language

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD" && ${OPSYS} != "Linux"
DEPENDS+=		gindent-[0-9]*:../../devel/gindent
.endif

USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/popt/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libIDL/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=	LIBWRAP_PATH=${BUILDLINK_PREFIX.tcp_wrappers}/lib/libwrap.a
CONFIGURE_ENV+=	LIB_WRAP="-lwrap"

PKGCONFIG_OVERRIDE+=	${WRKSRC}/ORBit.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libIDL/libIDL.pc.in

CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		15
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

.if ${OPSYS} == "SunOS"
post-buildlink:
	${MV} ${BUILDLINK_DIR}/lib/libpthread.la ${BUILDLINK_DIR}/lib/libpthread.la.old
	${GREP} -v libpthread.a ${BUILDLINK_DIR}/lib/libpthread.la.old >${BUILDLINK_DIR}/lib/libpthread.la
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
