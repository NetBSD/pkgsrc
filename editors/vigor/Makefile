# $NetBSD: Makefile,v 1.36 2012/10/03 11:43:45 asau Exp $
#

DISTNAME=	vigor-0.016
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vigor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vigor.sourceforge.net/
COMMENT=	nvi with excessive online "help"

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

CONFLICTS+=	nvi-[0-9]*

LDFLAGS+=	${BDB_LIBS}

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	build
CONFIGURE_ENV+=	TCLCONFIG_SH=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=	vi_cv_path_shell=${TOOLS_SH:Q}
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-re
USE_TOOLS+=	sh
BUILD_DIRS=	${CONFIGURE_DIRS}

BUILDLINK_DEPMETHOD.libXt?=	build

CHECK_BUILTIN.db1:=	yes
.include "../../mk/db1.builtin.mk"
CHECK_BUILTIN.db1:=	no

.if empty(IS_BUILTIN.db1:Myes)
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

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "DragonFly"
.if exists(/usr/include/sys/queue.h)
# this file obscures the system header
# (Desired for DragonFly which does not have CIRCLEQ macros)
post-patch:
	${RM} -f ${WRKSRC}/include/sys/queue.h
.endif
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
