# $NetBSD: Makefile,v 1.24 2003/01/05 19:26:16 jlam Exp $

DISTNAME=	postgresql-${DIST_VERS}
DIST_VERS=	7.2.3
BASE_VERS=	${DIST_VERS}
PKGNAME=	${PYPKGPREFIX}-postgresql-3.3
CATEGORIES=	databases
MASTER_SITES=	http://www.postgresql.org/ftpsite/source/v${DIST_VERS}/ \
		ftp://ftp.postgresql.org/pub/source/v${DIST_VERS}/ \
		ftp://ftp.de.postgresql.org/pub/source/v${DIST_VERS}/ \
		ftp://ch.postgresql.org/mirror/postgresql/source/v${DIST_VERS}/ \
		ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/source/v${DIST_VERS}/ \
		ftp://looking-glass.usask.ca/pub/postgresql/source/v${DIST_VERS}/ \
		ftp://ftp.sunsite.auc.dk/mirrors/postgresql/source/v${DIST_VERS}/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/source/v${DIST_VERS}/

CONFLICTS+=	postgresql-[0-6]* postgresql-7.0*

MAINTAINER=	darcy@netbsd.org
HOMEPAGE=	http://www.postgresql.org/
COMMENT=	Python interface to PostgreSQL

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
AUTOCONF_REQD=		2.13

.include "../../mk/bsd.prefs.mk"

# PG_MB_ENCODING may be set to any of:
#
# SQL_ASCII, EUC_JP, EUC_CN, EUC_KR, EUC_TW, UNICODE, MULE_INTERNAL,
# LATIN1, LATIN2, LATIN3, LATIN4, LATIN5, KOI8, WIN, ALT
#
# This variable controls the language encoding on the backend process.

.if defined(PG_MB_ENCODING)
CONFIGURE_ARGS+=	--enable-multibyte=${PG_MB_ENCODING}
.else
CONFIGURE_ARGS+=	--enable-multibyte	# accept default
.endif

CONFIGURE_ARGS+=	--without-CXX
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--disable-readline
CONFIGURE_ARGS+=	--enable-locale
CONFIGURE_ARGS+=	--enable-syslog
CONFIGURE_ARGS+=	--with-template="${LOWER_OPSYS}"

CONFIGURE_ARGS+=	--disable-odbc
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--without-tk
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ARGS+=	--with-python-compile
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

USE_GMAKE=		YES
MAKEFILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1
MAKEFLAGS+=		PYTHON_VERSION="${PYVERSSUFFIX}"

PLIST_SUBST+=		PYTHON_LIBDIR=${PYLIB}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

BUILD_DIRS=		${WRKSRC}/src/interfaces/python
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

post-extract:
	if [ -d ${WRKSRC}/src ]; then					\
		${RM} -f ${WRKSRC}/src/Makefile.custom;			\
		${CP} -f ${FILESDIR}/Makefile.custom			\
			${WRKSRC}/src/Makefile.custom;			\
	fi
	if [ -d ${WRKSRC}/src/interfaces/libpq ]; then			\
		${RM} -f ${WRKSRC}/src/interfaces/libpq/GNUmakefile;	\
		${CP} -f ${FILESDIR}/GNUmakefile.libpq			\
			${WRKSRC}/src/interfaces/libpq/GNUmakefile;	\
	fi

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	for file in ${WRKSRC}/src/interfaces/python/tutorial/*.py; do	\
		${INSTALL_DATA} $${file} ${DOCDIR}/tutorial;		\
	done

.include "../postgresql-lib/buildlink2.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
