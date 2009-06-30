# $NetBSD: Makefile,v 1.38 2009/06/30 00:07:18 joerg Exp $
#

DISTNAME=	tclx8.3.5-src
PKGNAME=	tcl-tclX-8.3.5
PKGREVISION=	3
CATEGORIES=	lang tcl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclx/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://tclx.sourceforge.net/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

.include "../../lang/tcl/Makefile.version"

CONFLICTS+=		tclX-[0-9]*
BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.4.7

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}/unix
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared \
			--with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--enable-tk=NO
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

PKGSRCDIR.tcl=		${.CURDIR}/../../lang/tcl
WRKSRC.tcl_cmd=		\
	cd ${PKGSRCDIR.tcl} && ${MAKE} show-var VARNAME=WRKSRC

PKGSRC_TCL_SRC_DIR=	${WRKSRC.tcl_cmd:sh}
CONFIGURE_ENV+=		PKGSRC_TCL_SRC_DIR=${PKGSRC_TCL_SRC_DIR:Q}

MAKE_ENV+=		CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} \
			SHAREMODE=${SHAREMODE:Q} SHAREOWN=${SHAREOWN:Q} \
			SHAREGRP=${SHAREGRP:Q} TCLX_PREFIX=${PREFIX:Q} \
			INSTALL_ROOT=${DESTDIR}

INSTALLATION_DIRS=	bin include

.include "../../lang/tcl/buildlink3.mk"

post-extract:
	@${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n
	@if [ ! -r ${PKGSRC_TCL_SRC_DIR} ]; then	\
		cd ${PKGSRCDIR.tcl} && ${MAKE} extract;			\
	fi

post-build:
	cd ${WRKSRC}/../tcl/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${DESTDIR}${PREFIX}/lib/tcl/tclX8.3/help -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/lib/tcl/tclX8.3/help -type f -print | ${XARGS} ${CHMOD} ${DOCMODE}
	@${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/TkX_Main.3
	@${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

pre-clean:
	@cd ${PKGSRCDIR.tcl} && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
