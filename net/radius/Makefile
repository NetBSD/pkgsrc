# $NetBSD: Makefile,v 1.1.1.1 1999/03/22 03:15:09 kim Exp $
#

DISTNAME=	radius-3.6B
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radius/releases/ \
		http://www.mr.net/~bradley/radius/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.merit.edu/aaa/

EXTRACT_ONLY=	radius.3.6B.basic.tar.gz \
		radius.3.6B-skey.tar.gz
EXTRA_FILES=	radius.3.6B-ftp.tar \
		radius.3.6B-simultd.tar

DIST_SUBDIR=	radius
NO_WRKSUBDIR=	yes

.include "../../mk/bsd.prefs.mk"

.ifmake do-build
.if exists(/usr/lib/libkrb.a) && \
    (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CFLAGS+=	-DM_KERB -I/usr/include/kerberosIV
RADLIBS=	-lkrb -ldes
.endif
.endif

post-extract:
	@cd ${WRKSRC} ; \
	for i in ${EXTRA_FILES} ; \
	do \
	    ${GTAR} -xf ${_DISTDIR}/$${i} ; \
	done

pre-patch:
	@cd ${WRKSRC} ; \
	${PATCH} -sp < prediff.diff ; \
	for i in ftp simult skey ; \
	do \
	    ${PATCH} -sp < rad.$${i}.diff ; \
	done

EXAMPLE_DIR=	${PREFIX}/share/examples/radius

do-install:
	@cd ${WRKSRC} ; \
	${MAKE} man-install ; \
	${MAKE} install ; \
	${MAKE} util-install ; \
	${MKDIR} ${EXAMPLE_DIR} ; \
	${MAKE} config-install RADDB_INSDIR=${EXAMPLE_DIR}

.include "../../mk/bsd.pkg.mk"

.ifmake do-build
CFLAGS+=	-DHAVE_SETVBUF -DNOSHADOW

MAKE_ENV+=	RADLIBS="${RADLIBS} -lskey"
MAKE_ENV+=	LIBS=-lcrypt

MAKE_ENV+=	GNUZIP="`${ECHO} ${GZIP_CMD} | ${AWK} '{print $$1}'`"
.endif

.ifmake do-install
MAKE_ENV+=	INSTALL="${INSTALL} -c"
.endif
