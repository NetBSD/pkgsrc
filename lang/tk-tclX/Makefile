# $NetBSD: Makefile,v 1.15 2004/03/08 20:27:14 minskim Exp $
#

DISTNAME=	tclX8.2.0
PKGNAME=	tk-tclX-8.2.0
CATEGORIES=	lang tcl tk
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/TclX/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.neosoft.com/TclX/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

DEPENDS+=	tk>=8.3.4:../../x11/tk83
DEPENDS+=	tcl-tclX-8.2.0:../../lang/tcl-tclX

CONFLICTS+=	tclX-[0-9]*

WRKSRC=		${WRKDIR}/tclX8.2.0/unix
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${PREFIX}/lib \
			--with-tk=${PREFIX}/lib
TEST_DIRS=		${WRKSRC}/../tk/unix
TEST_TARGET=		test

CONFIGURE_ENV+=		\
	PKGSRC_TCL_SRC_DIR="${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.3.4" \
	PKGSRC_TK_SRC_DIR="${_PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.3.4"

MAKE_ENV+=		GTAR=${GTAR} CHOWN=${CHOWN} CHMOD=${CHMOD} \
			SHAREMODE=${SHAREMODE} SHAREOWN=${SHAREOWN} \
			SHAREGRP=${SHAREGRP}

FILESDIR=	${.CURDIR}/../../lang/tcl-tclX/files
PATCHDIR=	${.CURDIR}/../../lang/tcl-tclX/patches

post-extract:
	${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n
	@if [ ! -e ${_PKGSRCDIR}/lang/tcl/${WRKDIR:T}/tcl8.3.4 ]; then	\
		cd ../../lang/tcl83 && ${MAKE} extract;			\
	fi
	@if [ ! -e ${_PKGSRCDIR}/x11/tk/${WRKDIR:T}/tk8.3.4 ]; then	\
		cd ../../x11/tk83 && ${MAKE} extract;			\
	fi

pre-clean:
	@cd ../../lang/tcl83 && ${MAKE} clean
	@cd ../../x11/tk83 && ${MAKE} clean

do-build:
	@cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE}

do-install:
	@cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE} install

post-build:
	cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type d -exec ${CHMOD} 555 '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type f -exec ${CHMOD} 444 '{}' \;

# 	@${RM} ${PREFIX}/man/man3/TkX_Main.3
# 	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

.include "../../mk/bsd.pkg.mk"
