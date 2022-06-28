# $NetBSD: Makefile,v 1.53 2022/06/28 11:33:49 wiz Exp $
#

DISTNAME=	vigor-0.016
PKGREVISION=	17
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vigor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vigor.sourceforge.net/
COMMENT=	Excessive online "help" version of nvi

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

CONFLICTS+=	nvi-[0-9]*

LDFLAGS+=	${BDB_LIBS}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		build
CONFIGURE_ENV+=		TCLCONFIG_SH=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=		vi_cv_path_shell=${TOOLS_SH}
CONFIGURE_ARGS+=	--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-re
USE_TOOLS+=		sh
BUILD_DIRS=		${CONFIGURE_DIRS}

BUILDLINK_DEPMETHOD.libXt?=	build

CHECK_BUILTIN.db1:=	yes
.include "../../mk/db1.builtin.mk"
CHECK_BUILTIN.db1:=	no

.if ${IS_BUILTIN.db1} != yes
CONFIGURE_ARGS+=	--disable-db
.else
SUBST_CLASSES+=		db185
SUBST_STAGE.db185=	post-extract
SUBST_MESSAGE.db185=	Using db_185.h instead of db.h
SUBST_FILES.db185=	common/common.h
SUBST_SED.db185=	-e '/^\#include <db\.h>/s/db\.h/db_185.h/'

BDB_ACCEPTED=		db1
.include "../../mk/bdb.buildlink3.mk"
.endif

CPPFLAGS+=	-DUSE_INTERP_RESULT

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "DragonFly"
.  if exists(/usr/include/sys/queue.h)
# this file obscures the system header
# (Desired for DragonFly which does not have CIRCLEQ macros)
post-patch:
	${RM} -f ${WRKSRC}/include/sys/queue.h
.  endif
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
