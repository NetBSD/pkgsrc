# $NetBSD: Makefile,v 1.17 2004/03/20 19:28:52 minskim Exp $
#

DISTNAME=	tclX8.2.0
PKGNAME=	tcl-tclX-8.2.0
PKGREVISION=	1
CATEGORIES=	lang tcl
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/TclX/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://tclx.sourceforge.net/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

CONFLICTS+=	tclX-[0-9]*

WRKSRC=			${WRKDIR}/tclX8.2.0/unix
USE_BUILDLINK2=		yes
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
			SHAREGRP=${SHAREGRP}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing Tcl library names."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	${WRKSRC}/../tcl/unix/Makefile.in
SUBST_SED.paths=	-e 's,ltcl83,ltcl,g'

.include "../../lang/tcl/buildlink2.mk"

post-extract:
	@${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n
	@if [ ! -e ${PKGSRC_TCL_SRC_DIR} ]; then	\
		cd ../../lang/tcl && ${MAKE} extract;			\
	fi

post-build:
	cd ${WRKSRC}/../tcl/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type d -exec ${CHMOD} 555 '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type f -exec ${CHMOD} 444 '{}' \;
	@${RM} ${PREFIX}/man/man3/TkX_Main.3
	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

pre-clean:
	@cd ../../lang/tcl && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
