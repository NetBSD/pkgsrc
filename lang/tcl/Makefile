# $NetBSD: Makefile,v 1.87 2016/02/19 15:15:42 jperkin Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Tool Command Language, a dynamic language
LICENSE=	2-clause-bsd

.include "../../lang/tcl/Makefile.version"

WRKSRC=			${WRKDIR}/tcl${TCL_VERSION}

USE_GCC_RUNTIME=	yes

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_TARGET=		install

PKGCONFIG_OVERRIDE+=	unix/tcl.pc.in

CHECK_PORTABILITY_SKIP=	win/configure

# The test target gives better results when not run as root.
TEST_TARGET=		test

.include "options.mk"

# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	ac_cv_func_gethostbyname_r=no
.endif

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

PLIST_SUBST+=		SONUM=${TCL_SONUM}
PLIST_SUBST+=		BASEVER=${TCL_BASEVER}

CONFIGURE_ARGS+=	--with-system-sqlite
SUBST_CLASSES+=		sqllink
SUBST_STAGE.sqllink=	pre-configure
SUBST_FILES.sqllink=	pkgs/sqlite3.8.8.3/configure
SUBST_SED.sqllink=	-e "/LIBS=/s|-lsqlite3|-L${BUILDLINK_PREFIX.sqlite3}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3|g"

.if ${OPSYS} == "Darwin"
post-build:
.  for lib in itcl4.0.3/libitcl4.0.3.dylib \
	      sqlite3.8.8.3/libsqlite3.8.8.3.dylib \
	      tdbc1.0.3/libtdbc1.0.3.dylib \
	      tdbcmysql1.0.3/libtdbcmysql1.0.3.dylib \
	      tdbcodbc1.0.3/libtdbcodbc1.0.3.dylib \
	      tdbcpostgres1.0.3/libtdbcpostgres1.0.3.dylib \
	      thread2.7.2/libthread2.7.2.dylib
	install_name_tool -id ${PREFIX}/lib/${lib} ${WRKSRC}/unix/pkgs/${lib}
.  endfor
.endif

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.8.3
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
