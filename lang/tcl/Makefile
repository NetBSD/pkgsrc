# $NetBSD: Makefile,v 1.31 2004/04/09 23:37:28 danw Exp $
#

DISTNAME=		tcl8.4.6-src
PKGNAME=		tcl-8.4.6
PKGREVISION=		3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=		jwise@NetBSD.org
HOMEPAGE=		http://www.tcl.tk/
COMMENT=		Ousterhout's Tool Command Language, a scripting language

CONFLICTS+=		tclman80-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:C/-src//}/unix
GNU_CONFIGURE=		yes
MAKE_ENV+=		TOUCH="${TOUCH}"
TEST_TARGET=		test

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

INSTALL_TARGET=		install

# Initially install the man pages into ${WRKDIR}/man, as we need a staged
# install to avoid overwriting existing manpages in ${PREFIX}/man.
#
CONFIGURE_ARGS+=	--mandir=${WRKDIR}/man
CONFIGURE_ARGS+=	--enable-threads

# Add ${VIEWBASE}/lib/tcl to the list of locations for Tcl packages.
CONFIGURE_ENV+=		TCL_PACKAGE_PATH="${VIEWBASE}/lib/tcl"

.include "../../mk/bsd.prefs.mk"

# NetBSD-1.5.x-m68k platforms apparently have a compiler optimization bug
# tickled by the Tcl code that manifests in code generation problems.
#
.if (${MACHINE_PLATFORM:MNetBSD-1.5*-m68k} != "")
CONFIGURE_ENV+=		COMPILER_OPTIMIZATION_BUG=YES
.endif

.include "../../mk/pthread.buildlink3.mk"

# Modify mkLinks script to remove the short-filename manpage if it was
# linked to a longer filename.
#
post-patch:
	@cd ${WRKSRC};							\
	${MV} -f mkLinks mkLinks.tmp;					\
	${GREP} -v "^exit 0" mkLinks.tmp > mkLinks;			\
	${CAT} mkLinks.tmp						\
		| ${AWK} '/^  *ln / { print $$3 }'			\
		| ${SORT} -u						\
		| ${GREP} -v ".*\.n"					\
		| ${SED} -e "s,^,${RM} -f ,"				\
		>> mkLinks;						\
	${RM} -f mkLinks.tmp;						\
	${CHMOD} +x mkLinks;

post-install:
	cd ${WRKDIR} && ${PAX} -rwpm man ${PREFIX}
	${RM} -rf ${WRKDIR}/man
	cd ${PREFIX}/bin && ${LN} -s tclsh8.4 tclsh
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

.include "../../mk/bsd.pkg.mk"
