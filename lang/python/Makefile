# $NetBSD: Makefile,v 1.17 1999/08/02 10:59:34 agc Exp $
#

DISTNAME=	py152
PKGNAME=	python-1.5.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

DIST_SUBDIR=	python

WRKSRC=		${WRKDIR}/Python-1.5.2
GNU_CONFIGURE=	yes

# Make sure having environment variable OPT doesn't affect the
# installed module-building Makefile
MAKE_ENV+=	'OPT=${CFLAGS}'
CONFIGURE_ENV+=	'OPT=${CFLAGS}'
SCRIPTS_ENV+=	'OPT=${CFLAGS}'

# Handle the module setup file:
#   - disable a few broken modules on 64 bit platforms (nothing important)
#   - handle machines with no dynamic loader

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc64"
NO64BIT=\#
.endif
.if ${MACHINE_ARCH} == "sparc64"
NOSHARED=\#
.endif
.if ${OPSYS} == "SunOS"
ZOULARIS?=	${PREFIX}/bsd
MODADD=		-I${ZOULARIS}/include -L${ZOULARIS}/lib -R${ZOULARIS}/lib
.endif

post-configure:
	${SED}  -e 's,@NO64BIT@,${NO64BIT},g' \
		-e 's,@NOSHARED@,${NOSHARED},g' \
		-e 's,@MODADD@,${MODADD},g' \
		${FILESDIR}/Setup >${WRKSRC}/Modules/Setup

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; find lib/python1.5 -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find include/python1.5 -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d include/python1.5 -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${ECHO} "@unexec ${RM} -rf %D/lib/python1.5" >>${PLIST_SRC}
	# Reinstall Python binary to get it stripped
	${RM} ${PREFIX}/bin/python ${PREFIX}/bin/python1.5
	${INSTALL_PROGRAM} ${WRKSRC}/python ${PREFIX}/bin
	${LN} ${PREFIX}/bin/python ${PREFIX}/bin/python1.5

.include "../../mk/bsd.pkg.mk"
