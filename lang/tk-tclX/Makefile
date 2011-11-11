# $NetBSD: Makefile,v 1.36 2011/11/11 19:16:27 joerg Exp $
#

DISTNAME=	tclx8.3.5-src
PKGNAME=	tk-tclX-8.3.5
PKGREVISION=	3
CATEGORIES=	lang tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tclx.sourceforge.net/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/tcl/Makefile.version"
.include "../../x11/tk/Makefile.version"

CONFLICTS+=	tclX-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}/unix
USE_TOOLS+=		gtar
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared \
			--with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib
TEST_DIRS=		${WRKSRC}/../tk/unix
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

PKGSRCDIR.tcl=		${.CURDIR}/../../lang/tcl
PKGSRCDIR.tk=		${.CURDIR}/../../x11/tk
WRKSRC.tcl_cmd=		\
	cd ${PKGSRCDIR.tcl} && ${MAKE} show-var VARNAME=WRKSRC
WRKSRC.tk_cmd=		\
	cd ${PKGSRCDIR.tk} && ${MAKE} show-var VARNAME=WRKSRC

PKGSRC_TCL_SRC_DIR=	${WRKSRC.tcl_cmd:sh}
PKGSRC_TK_SRC_DIR=	${WRKSRC.tk_cmd:sh}
CONFIGURE_ENV+=		PKGSRC_TCL_SRC_DIR=${PKGSRC_TCL_SRC_DIR:Q} \
			PKGSRC_TK_SRC_DIR=${PKGSRC_TK_SRC_DIR:Q}

MAKE_ENV+=		GTAR=${GTAR:Q} CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} \
			SHAREMODE=${SHAREMODE:Q} SHAREOWN=${SHAREOWN:Q} \
			SHAREGRP=${SHAREGRP:Q} \
			TCLX_PREFIX=${BUILDLINK_PREFIX.tcl-tclX} \
			INSTALL_ROOT=${DESTDIR}

FILESDIR=	${.CURDIR}/../../lang/tcl-tclX/files
PATCHDIR=	${.CURDIR}/../../lang/tcl-tclX/patches
DISTINFO_FILE=	${.CURDIR}/../../lang/tcl-tclX/distinfo

INSTALLATION_DIRS=	bin include

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-tclX/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-extract:
	${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n
	@if [ ! -r ${PKGSRC_TCL_SRC_DIR} ]; then	\
		cd ${PKGSRCDIR.tcl} && ${MAKE} extract;			\
	fi
	@if [ ! -r ${PKGSRC_TK_SRC_DIR} ]; then	\
		cd ${PKGSRCDIR.tk} && ${MAKE} extract;			\
	fi

pre-clean:
	@cd ../../lang/tcl && ${MAKE} clean
	@cd ../../x11/tk && ${MAKE} clean

do-build:
	@cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE}

do-install:
	@cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE} install

post-build:
	cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${DESTDIR}${PREFIX}/lib/tcl/tclX8.3/help -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/lib/tcl/tclX8.3/help -type f -print | ${XARGS} ${CHMOD} ${DOCMODE}

# 	@${RM} ${PREFIX}/${PKGMANDIR}/man3/TkX_Main.3
# 	@${RM} ${PREFIX}/${PKGMANDIR}/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

.include "../../mk/bsd.pkg.mk"
