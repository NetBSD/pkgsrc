# $NetBSD: Makefile,v 1.37 2016/02/14 10:19:22 jperkin Exp $

DISTNAME=	unixODBC-2.3.4
PKGNAME=	${DISTNAME:S/ODBC/odbc/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.unixodbc.org/pub/unixODBC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unixodbc.org/
COMMENT=	ODBC 2.x/3.x driver manager
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=		iodbc<3.52.7nb2

USE_LIBTOOL=		yes
USE_TOOLS+=		flex yacc # to get libodbctxt.la
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--enable-driverc
CONFIGURE_ARGS+=	--enable-drivers
CONFIGURE_ARGS+=	--enable-threads
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CONFIGURE_ARGS+=	--enable-gnuthreads
CONFIGURE_ARGS+=	--with-pth=${PTHREADBASE:Q}
.endif

LIBS.SunOS+=		-lsocket -lnsl

# Override the local definitions that point to the self-contained libtool
# convenience library.  We want the one installed by pkgsrc.  Also override
# the variable pointing to the (static) libfl.a, which won't link with a
# shared library.  The sources define all the relevant symbols (yywrap), so
# libfl.a isn't needed.
MAKE_FLAGS+=		LEXLIB=""
MAKE_ENV+=		AM_MAKEFLAGS=${MAKE_FLAGS:Q}

UNIXODBC_DRIVERS_DIR=	lib/unixodbc

PLIST_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}
FILES_SUBST+=		UNIXODBC_DRIVERS_DIR=${UNIXODBC_DRIVERS_DIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/odbc.ini ${PKG_SYSCONFDIR}/odbc.ini
OWN_DIRS=		${PKG_SYSCONFDIR}/ODBCDataSources

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	${WRKDIR}/odbc.ini
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@UNIXODBC_DRIVERS_DIR@,${UNIXODBC_DRIVERS_DIR},g'

SUBST_CLASSES+=		mutex
SUBST_STAGE.mutex=	pre-configure
SUBST_FILES.mutex=	DriverManager/__handles.c odbcinst/_logging.c
SUBST_FILES.mutex+=	odbcinst/SQLGetPrivateProfileString.c
SUBST_SED.mutex=	-e 's,mutex_exit,odbc_mutex_exit,g'

INSTALLATION_DIRS=	${EGDIR}

post-extract:
	${CP} ${FILESDIR}/odbcinst.ini.in ${WRKDIR}/odbc.ini

post-patch:
	set -e; cd ${WRKSRC};					\
	files=`${FIND} DRVConfig Drivers -name Makefile.in -print`;\
	for file in $${files}; do				\
		sed -e "s|^\(libdir =\).*|\1 ${PREFIX}/${UNIXODBC_DRIVERS_DIR}|g" \
			$${file} >> $${file}.fixed;		\
		mv -f $${file}.fixed $${file};			\
	done
	set -e; cd ${WRKSRC};					\
	files=`${FIND} . -name Makefile.in -print`;		\
	for file in $${files}; do				\
		sed	-e "/DEPENDENCIES/s|\$$(LIBLTDL)||g"	\
			-e "/LIBADD/s|@LEXLIB@|\$$(LEXLIB)|g"	\
			$${file} >> $${file}.fixed;		\
		mv -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA} ${WRKDIR}/odbc.ini ${DESTDIR}${EGDIR}/odbc.ini

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
