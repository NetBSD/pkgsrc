# $NetBSD: Makefile,v 1.14 2001/12/23 17:02:30 bjoern Exp $
#

DISTNAME=		tcl8.3.4
PKGNAME=		tcl-8.3.4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_3/ \
			ftp://gd.tuwien.ac.at/languages/tcl/scriptics/tcl8_3/ \
			ftp://ftp.funet.fi/pub/languages/tcl/tcl/tcl8_3/ \
			ftp://ftp.mpi-sb.mpg.de/pub/tcl/mirror/ftp.scriptics.com/tcl8_3/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.tcltk.com/
COMMENT=		Ousterhout's Tool Command Language, a scripting language

CONFLICTS+=		tclman80-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=		yes
MAKE_ENV+=		TOUCH="${TOUCH}"

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes

INSTALL_TARGET=		install

# Initially install the man pages into ${WRKDIR}/man, as we need a staged
# install to avoid overwriting existing manpages in ${PREFIX}/man.
#
CONFIGURE_ARGS+=	--mandir=${WRKDIR}/man

.include "../../mk/bsd.prefs.mk"

# NetBSD-1.5.x-m68k platforms apparently have a compiler optimization bug
# tickled by the Tcl code that manifests in code generation problems.
#
.if (${MACHINE_PLATFORM:MNetBSD-1.5*-m68k} != "")
CONFIGURE_ENV+=		COMPILER_OPTIMIZATION_BUG=YES
.endif

# Modify mkLinks script to remove the short-filename manpage if it was
# linked to a longer filename.
#
post-patch:
	@cd ${WRKSRC};							\
	${MV} -f mkLinks mkLinks.tmp;					\
	${GREP} -v "^exit 0" mkLinks.tmp > mkLinks;			\
	${CAT} mkLinks.tmp						\
		| ${AWK} '/^  *ln / { print $$2 }'			\
		| ${SORT} -u						\
		| ${GREP} -v ".*\.n"					\
		| ${SED} -e "s,^,${RM} -f ,"				\
		>> mkLinks;						\
	${RM} -f mkLinks.tmp;						\
	${CHMOD} +x mkLinks;

post-install:
	${CHMOD} -R ugo-w ${WRKDIR}/man
	cd ${WRKDIR}; ${PAX} -rw man ${PREFIX}
	${CHMOD} -R ug+rw ${WRKDIR}/man
	cd ${PREFIX}/bin && ${LN} -s tclsh8.3 tclsh
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl/unix
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/tclUnixPort.h ${PREFIX}/include/tcl/unix
	${INSTALL_DATA} ${WRKSRC}/../generic/tcl.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclCompile.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclIO.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclInitScript.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclInt.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclIntDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclIntPlatDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclMath.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclPlatDecls.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclPort.h ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tclRegexp.h ${PREFIX}/include/tcl/generic

test:
	cd ${WRKSRC} && ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
