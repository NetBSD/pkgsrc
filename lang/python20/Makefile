# $NetBSD: Makefile,v 1.4 2002/01/28 11:51:23 drochner Exp $
#

DISTNAME=	Python-2.0.1
PKGNAME=	python20-2.0.1
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.0.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

CONFLICTS+=	python-2.0.*

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

DIST_SUBDIR=	python

WRKSRC=		${WRKDIR}/Python-2.0.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-threads
INSTALL_TARGET=	altinstall

# Make sure having environment variable OPT doesn't affect the
# installed module-building Makefile
MAKE_ENV+=	'OPT=${CFLAGS}'
CONFIGURE_ENV+=	'OPT=${CFLAGS}'
SCRIPTS_ENV+=	'OPT=${CFLAGS}'

# If Building on NetBSD 1.5, include SSL support
.if exists(/usr/include/openssl/ssl.h)
SSLFLAGS=	-DUSE_SSL -I/usr/include/openssl -lssl -lcrypto
.endif

# Handle the module setup file:
#   - disable a few broken modules on 64 bit platforms (nothing important)

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ZOULARIS?=	${PREFIX}/bsd
MODADD=		-I${ZOULARIS}/include -L${ZOULARIS}/lib -R${ZOULARIS}/lib
.endif

pre-configure:
	${SED}  -e 's,@NOSHARED@,${NOSHARED},g' \
		-e 's,@MODADD@,${MODADD},g' \
		-e 's,@SSLFLAGS@,${SSLFLAGS},g' \
		${FILESDIR}/Setup.in >${WRKSRC}/Modules/Setup.in
	${SED}  -e 's,@NOSHARED@,${NOSHARED},g' \
		-e 's,@MODADD@,${MODADD},g' \
		${FILESDIR}/Setup.config.in >${WRKSRC}/Modules/Setup.config.in

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

.include "../../mk/bsd.pkg.mk"
