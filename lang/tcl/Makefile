# $NetBSD: Makefile,v 1.94 2016/12/04 05:17:31 ryoon Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
PKGREVISION=	1
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
PLIST_SUBST+=		ITCL_VERSION=${ITCL_VERSION}
PLIST_SUBST+=		TDBC_VERSION=${TDBC_VERSION}

CONFIGURE_ARGS+=	--with-system-sqlite
SUBST_CLASSES+=		sqllink
SUBST_STAGE.sqllink=	pre-configure
SUBST_FILES.sqllink=	pkgs/sqlite3.13.0/configure
SUBST_SED.sqllink=	-e "/LIBS=/s|-lsqlite3|-L${BUILDLINK_PREFIX.sqlite3}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3|g"

.if ${OPSYS} == "Darwin"
post-build:
.  for lib in itcl${ITCL_VERSION}/libitcl${ITCL_VERSION}.dylib \
	      sqlite3.13.0/libsqlite3.13.0.dylib \
	      tdbc${TDBC_VERSION}/libtdbc${TDBC_VERSION}.dylib \
	      tdbcmysql${TDBC_VERSION}/libtdbcmysql${TDBC_VERSION}.dylib \
	      tdbcodbc${TDBC_VERSION}/libtdbcodbc${TDBC_VERSION}.dylib \
	      tdbcpostgres${TDBC_VERSION}/libtdbcpostgres${TDBC_VERSION}.dylib \
	      thread2.8.0/libthread2.8.0.dylib
	install_name_tool -id ${PREFIX}/lib/${lib} ${WRKSRC}/unix/pkgs/${lib}
.  endfor
.endif

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.13.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
