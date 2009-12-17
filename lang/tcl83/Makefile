# $NetBSD: Makefile,v 1.19 2009/12/17 18:35:26 abs Exp $
#

DISTNAME=		tcl8.3.4
PKGNAME=		tcl-8.3.4
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.funet.fi/pub/languages/tcl/tcl/tcl8_3/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tcltk.com/
COMMENT=		Ousterhout\'s Tool Command Language, a scripting language

CONFLICTS+=		tclman80-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
MAKE_ENV+=		TOUCH=${TOUCH:Q}
TEST_TARGET=		test

USE_LIBTOOL=		yes

INSTALL_TARGET=		install

# Add ${VIEWBASE}/lib/tcl to the list of locations for Tcl packages.
CONFIGURE_ENV+=		TCL_PACKAGE_PATH="${VIEWBASE}/lib/tcl"

PKG_DESTDIR_SUPPORT=  user-destdir
INSTALLATION_DIRS+= include/tcl/unix include/tcl/generic

.include "../../mk/bsd.prefs.mk"

# NetBSD-1.5.x-m68k platforms apparently have a compiler optimization bug
# tickled by the Tcl code that manifests in code generation problems.
#
.if (${MACHINE_PLATFORM:MNetBSD-1.5*-m68k} != "")
CONFIGURE_ENV+=		COMPILER_OPTIMIZATION_BUG=YES
.endif

.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

# Modify mkLinks script to remove the short-filename manpage if it was
# linked to a longer filename.
#
post-patch:
	cd ${WRKSRC}/unix;						\
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

post-build:
	cd ${WRKSRC}/unix; for file in					\
		tclUnixInit.o libtcl83.so tclsh;			\
	do								\
		${TOUCH} $${file};					\
	done
	${SED} 								\
		-e "s|${WRKSRC}/unix|${PREFIX}/lib|"			\
		-e "s|${WRKSRC}|${PREFIX}/include/tcl|"			\
		${WRKSRC}/unix/tclConfig.sh > ${WRKSRC}/tclConfig.sh.tmp &&	\
		${MV} ${WRKSRC}/tclConfig.sh.tmp ${WRKSRC}/unix/tclConfig.sh

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s tclsh8.3 tclsh
	${INSTALL_DATA} ${WRKSRC}/unix/tclUnixPort.h ${DESTDIR}${PREFIX}/include/tcl/unix
	${INSTALL_DATA} ${WRKSRC}/generic/tcl.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclCompile.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclDecls.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclIO.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclInitScript.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclInt.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclIntDecls.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclIntPlatDecls.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclMath.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclPlatDecls.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclPort.h ${DESTDIR}${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tclRegexp.h ${DESTDIR}${PREFIX}/include/tcl/generic

.include "../../mk/bsd.pkg.mk"
