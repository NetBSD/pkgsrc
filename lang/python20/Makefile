# $NetBSD: Makefile,v 1.35 2008/01/18 05:06:44 tnn Exp $
#

DISTNAME=	Python-2.0.1
PKGNAME=	python20-2.0.1
PKGREVISION=	14
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.0.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

CONFLICTS+=	python-[0-9]*
CONFLICTS+=	python-2.0.*

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

WRKSRC=		${WRKDIR}/Python-2.0.1
DIST_SUBDIR=	python

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-threads
INSTALL_TARGET=	altinstall

# Make sure having environment variable OPT doesn't affect the
# installed module-building Makefile
MAKE_ENV+=	'OPT=${CFLAGS}'
CONFIGURE_ENV+=	'OPT=${CFLAGS}'

SSLFLAGS=	-DUSE_SSL -I${BUILDLINK_PREFIX.openssl}/include/openssl \
		-L${BUILDLINK_PREFIX.openssl}/lib \
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto
FIX_RPATH+=	SSLFLAGS

# Handle the module setup file:
#   - disable a few broken modules on 64 bit platforms (nothing important)

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PRIVILEGED_STAGES+=	clean
.endif

.if ${OPSYS} == "SunOS"
ZOULARIS?=	${PREFIX}/bsd
MODADD=		-I${ZOULARIS}/include -L${ZOULARIS}/lib ${COMPILER_RPATH_FLAG}${ZOULARIS}/lib
FIX_RPATH+=	MODADD
.endif

REPLACE_INTERPRETER+=	py
REPLACE.py.old=		.*python
REPLACE.py.new=		${PREFIX}/bin/python2.0
REPLACE_FILES.py=	Lib/cgi.py

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/python2.0 -type f -print | \
		${GREP} -v site-packages >>${PLIST_SRC})
	${ECHO} lib/python2.0/site-packages/README >>${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} include/python2.0 -type f -print \
		>>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d include/python2.0 -type d -print | \
		${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d lib/python2.0 -type d -print | \
		${GREP} -v site-packages | \
		${GREP} -vx lib/python2.0 | \
		${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${ECHO} "@dirrm lib/python2.0/site-packages" >>${PLIST_SRC}
	${ECHO} "@dirrm lib/python2.0" >>${PLIST_SRC}
	# Reinstall Python binary to get it stripped
	${RM} ${PREFIX}/bin/python2.0
	${INSTALL_PROGRAM} ${WRKSRC}/python ${PREFIX}/bin/python2.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
