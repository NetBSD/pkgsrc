# $NetBSD: Makefile,v 1.26 2005/05/16 01:15:32 jlam Exp $
#

DISTNAME=	tclx8.3.5-src
PKGNAME=	tk-tclX-8.3.5
PKGREVISION=	2
CATEGORIES=	lang tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclx/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://tclx.sourceforge.net/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

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

CONFIGURE_ENV+=		\
	PKGSRC_TCL_SRC_DIR="${PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.4.9" \
	PKGSRC_TK_SRC_DIR="${PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.4.9"

MAKE_ENV+=		GTAR=${GTAR} CHOWN=${CHOWN} CHMOD=${CHMOD} \
			SHAREMODE=${SHAREMODE} SHAREOWN=${SHAREOWN} \
			SHAREGRP=${SHAREGRP} \
			TCLX_PREFIX=${BUILDLINK_PREFIX.tcl-tclX}

FILESDIR=	${.CURDIR}/../../lang/tcl-tclX/files
PATCHDIR=	${.CURDIR}/../../lang/tcl-tclX/patches
DISTINFO_FILE=	${.CURDIR}/../../lang/tcl-tclX/distinfo

INSTALLATION_DIRS=	bin include

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-tclX/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-extract:
	${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n
	@if [ ! -r ${PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.4.8 ]; then	\
		cd ../../lang/tcl && ${MAKE} extract;			\
	fi
	@if [ ! -r ${PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.4.8 ]; then	\
		cd ../../x11/tk && ${MAKE} extract;			\
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
	${FIND} ${PREFIX}/lib/tcl/tclX8.3/help -type d -exec ${CHMOD} ${PKGDIRMODE} '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.3/help -type f -exec ${CHMOD} ${DOCMODE} '{}' \;

# 	@${RM} ${PREFIX}/man/man3/TkX_Main.3
# 	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

.include "../../mk/bsd.pkg.mk"
