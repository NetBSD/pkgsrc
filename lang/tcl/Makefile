# $NetBSD: Makefile,v 1.37 2004/10/01 13:35:37 adam Exp $

DISTNAME=	tcl8.4.7-src
PKGNAME=	tcl-8.4.7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Ousterhout's Tool Command Language, a scripting language

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
CONFIGURE_ARGS+=	--mandir=${WRKDIR}/man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56].*)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
.endif

# Add ${VIEWBASE}/lib/tcl to the list of locations for Tcl packages.
CONFIGURE_ENV+=		TCL_PACKAGE_PATH="${VIEWBASE}/lib/tcl"

# NetBSD-1.5.x-m68k platforms apparently have a compiler optimization bug
# tickled by the Tcl code that manifests in code generation problems.
.if (${MACHINE_PLATFORM:MNetBSD-1.5*-m68k} != "")
CONFIGURE_ENV+=		COMPILER_OPTIMIZATION_BUG=YES
.endif

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56].*)
.include "../../mk/pthread.buildlink3.mk"
.endif
.endif

# Modify mkLinks script to remove the short-filename manpage if it was
# linked to a longer filename.
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
.for f in	regex.h tcl.h tclCompile.h tclDecls.h tclIO.h		\
		tclInitScript.h tclInt.h tclIntDecls.h tclIntPlatDecls.h\
		tclMath.h tclPlatDecls.h tclPort.h tclRegexp.h
	${INSTALL_DATA} ${WRKSRC}/../generic/${f} ${PREFIX}/include/tcl/generic
.endfor

.include "../../mk/bsd.pkg.mk"
