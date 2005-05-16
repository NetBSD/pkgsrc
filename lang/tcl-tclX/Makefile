# $NetBSD: Makefile,v 1.29 2005/05/16 01:15:32 jlam Exp $
#

DISTNAME=	tclx8.3.5-src
PKGNAME=	tcl-tclX-8.3.5
PKGREVISION=	2
CATEGORIES=	lang tcl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclx/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://tclx.sourceforge.net/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

.include "../../lang/tcl/Makefile.version"

CONFLICTS+=		tclX-[0-9]*
BUILDLINK_DEPENDS.tcl+=	tcl>=8.4.7

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}/unix
USE_TOOLS+=		gtar
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared \
			--with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--enable-tk=NO
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

PKGSRC_TCL_SRC_DIR=	${PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl${TCL_VERSION}
CONFIGURE_ENV+=		PKGSRC_TCL_SRC_DIR="${PKGSRC_TCL_SRC_DIR}"

MAKE_ENV+=		GTAR=${GTAR} CHOWN=${CHOWN} CHMOD=${CHMOD} \
			SHAREMODE=${SHAREMODE} SHAREOWN=${SHAREOWN} \
			SHAREGRP=${SHAREGRP} \
			TCLX_PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin include

.include "../../lang/tcl/buildlink3.mk"

post-extract:
	@${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n
	@if [ ! -r ${PKGSRC_TCL_SRC_DIR} ]; then	\
		cd ../../lang/tcl && ${MAKE} extract;			\
	fi

post-build:
	cd ${WRKSRC}/../tcl/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${PREFIX}/lib/tcl/tclX8.3/help -type d -exec ${CHMOD} ${PKGDIRMODE} '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.3/help -type f -exec ${CHMOD} ${DOCMODE} '{}' \;
	@${RM} ${PREFIX}/man/man3/TkX_Main.3
	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

pre-clean:
	@cd ../../lang/tcl && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
