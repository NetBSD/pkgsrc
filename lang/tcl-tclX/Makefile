# $NetBSD: Makefile,v 1.21 2004/10/03 00:15:03 tv Exp $
#

DISTNAME=	tclx8.3.5-src
PKGNAME=	tcl-tclX-8.3.5
PKGREVISION=	1
CATEGORIES=	lang tcl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclx/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://tclx.sourceforge.net/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

CONFLICTS+=		tclX-[0-9]*
BUILDLINK_DEPENDS.tcl+=	tcl>=8.4.6nb4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}/unix
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared \
			--with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--enable-tk=NO
TEST_TARGET=		test

PKGSRC_TCL_SRC_DIR=	${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.4.6
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
	${FIND} ${PREFIX}/lib/tcl/tclX8.3/help -type d -exec ${CHMOD} 555 '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.3/help -type f -exec ${CHMOD} 444 '{}' \;
	@${RM} ${PREFIX}/man/man3/TkX_Main.3
	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

pre-clean:
	@cd ../../lang/tcl && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
