# $NetBSD: Makefile,v 1.40 2012/07/13 15:52:54 fhajny Exp $

DISTNAME=	libevent-2.0.19-stable
PKGNAME=	${DISTNAME:S/-stable//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=levent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libevent.org/
COMMENT=	Asynchronous event notification library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	libev<3.9nb1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libevent_openssl.pc.in
PKGCONFIG_OVERRIDE+=	libevent_pthreads.pc.in
PKGCONFIG_OVERRIDE+=	libevent.pc.in
REPLACE_PYTHON=		event_rpcgen.py
TEST_TARGET=		verify

LIBS.SunOS+=	-lnsl -lresolv
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

# XXX helps build, but needs more testing
#CFLAGS.Interix+=	-Dsockaddr_storage=sockaddr_in -DNI_MAXSERV=32

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MHPUX-11.11-*)
CONFIGURE_ENV+=		ac_cv_func_strtoll=yes
CPPFLAGS+=		-Dstrtoll=__strtoll
.endif

.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
