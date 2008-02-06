# $NetBSD: Makefile,v 1.1.1.1 2008/02/06 04:22:33 bjs Exp $
#

DISTNAME=	js-1.6.20070208
PKGNAME=	ossp-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/js/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	ftp://ftp.ossp.org/pkg/lib/js/
COMMENT=	Sanitized distribution of Mozilla's JavaScript implementation

PKG_DESTDIR_SUPPORT=	user-destdir

###
### XXX This could be eliminated with buildlinkery, but I do not have time
###	right now.  You'll probably want to use this package in lieu of
###	spidermonkey anyway.
###
CONFLICTS+=		spidermonkey-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	js.pc.in

CONFIGURE_ARGS+=	--with-dso
CONFIGURE_ARGS+=	--with-editline
CONFIGURE_ARGS+=	--with-file
CONFIGURE_ARGS+=	--without-perl

REPLACE_SH=		js-config.sh.in

REPLACE_INTERPRETER+=	js
REPLACE.js.old=	./js
REPLACE.js.new=	${PREFIX}/bin/js
REPLACE_FILES.js=	jslint.js jspack.js

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_DEVELOPER)
CPPFLAGS+=	-Wall
.endif

###
### XXX I took this from jslibmath.h.  If this is not correct, please feel
### 	free to change it.  Our lang/spidermonkey package never uses
### 	the Sun math library, and I'm not sure if this is correct.
###
JS_FDLIBM_PLATFORMS=	Linux-*-* IRIX-*-* SunOS-*-* \
 	 	 	Solaris-*-* AIX-*-* HPUX-*-*

.if !empty(JS_FDLIBM_PLATFORMS:M${MACHINE_PLATFORM})
CPPFLAGS+=		-DPKG_FDLIBM_MATH_REQUESTED=1
MAKE_ENV+=		-DPKG_FDLIBM_MATH_REQUESTED=1
CONFIGURE_ENV+=		LIBM=""
.else
CPPFLAGS+=		-DPKG_FDLIBM_MATH_REQUESTED=0
CONFIGURE_ENV+=		LIBM="-lm"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
