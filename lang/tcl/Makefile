# $NetBSD: Makefile,v 1.89 2016/03/06 11:47:49 adam Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
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

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no

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
SUBST_FILES.sqllink=	pkgs/sqlite3.11.0/configure
SUBST_SED.sqllink=	-e "/LIBS=/s|-lsqlite3|-L${BUILDLINK_PREFIX.sqlite3}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3|g"

.if ${OPSYS} == "Darwin"
post-build:
.  for lib in itcl4.0.4/libitcl4.0.4.dylib \
	      sqlite3.11.0/libsqlite3.11.0.dylib \
	      tdbc1.0.4/libtdbc1.0.4.dylib \
	      tdbcmysql1.0.4/libtdbcmysql1.0.4.dylib \
	      tdbcodbc1.0.4/libtdbcodbc1.0.4.dylib \
	      tdbcpostgres1.0.4/libtdbcpostgres1.0.4.dylib \
	      thread2.7.3/libthread2.7.3.dylib
	install_name_tool -id ${PREFIX}/lib/${lib} ${WRKSRC}/unix/pkgs/${lib}
.  endfor
.endif

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.11.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
