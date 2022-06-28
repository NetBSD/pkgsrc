# $NetBSD: Makefile,v 1.21 2022/06/28 11:34:14 wiz Exp $
#

DISTNAME=	js-1.6.20070208
PKGNAME=	ossp-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/js/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ossp.org/pkg/lib/js/
COMMENT=	Sanitized distribution of Mozilla's JavaScript implementation

###
### XXX This could be eliminated with buildlinkery, but I do not have time
###	right now.  You'll probably want to use this package in lieu of
###	spidermonkey anyway.
###
CONFLICTS+=		spidermonkey-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CFLAGS+=		-Wall

PKGCONFIG_OVERRIDE+=	js.pc.in

CONFIGURE_ARGS+=	--with-dso
CONFIGURE_ARGS+=	--with-editline
CONFIGURE_ARGS+=	--with-file
CONFIGURE_ARGS+=	--without-perl

REPLACE_SH=		js-config.sh.in

REPLACE_INTERPRETER+=	js
REPLACE.js.old=		./js
REPLACE.js.new=		${PREFIX}/bin/js
REPLACE_FILES.js=	jslint.js jspack.js

.include "libm.mk"

.if !empty(JS_FDLIBM_MATH_REQUESTED:M[Yy][Ee][Ss])
MAKE_ENV+=		-DJS_FDLIBM_MATH_REQUESTED=1
CONFIGURE_ENV+=		LIBM=""
.else
CONFIGURE_ENV+=		LIBM="-lm"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
