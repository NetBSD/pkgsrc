# $NetBSD: Makefile,v 1.5 1999/04/24 23:19:05 tron Exp $
#
# Tempted to install another radius package?
#
#	Please consider e-mailing ${MAINTAINER} first with your concerns.
#	It would be nice to just fold new extensions into this code, and
#	avoid a myriad of incompatible radiusd incarnations.
#

DISTNAME=	radius-3.6B
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radius/releases/ \
		http://www.mr.net/~bradley/radius/
DISTFILES=	radius.3.6B.basic.tar.gz \
		radius.3.6B-skey.tar.gz \
		radius.3.6B-ftp.tar \
		radius.3.6B-simultd.tar

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.merit.edu/aaa/

DECOMPRESS_CMD=	${GZCAT} -f
DIST_SUBDIR=	radius
NO_WRKSUBDIR=	yes
INSTALL_TARGET=	man-install install util-install config-install

CFLAGS+=	-DHAVE_SETVBUF -DNOSHADOW
MAKE_ENV+=	RADLIBS="${RADLIBS} -lskey" LIBS=-lcrypt \
		GNUZIP="`${ECHO} ${GZIP_CMD} | ${AWK} '{print $$1}'`" \
		INSTALL="${INSTALL} -c" RADDB_INSDIR=${EXAMPLE_DIR}

# XXX Kerberos IV support is known to be broken.
#.if exists(/usr/lib/libkrb.a) && \
#    (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
#CFLAGS+=	-DM_KERB -I/usr/include/kerberosIV
#RADLIBS=	-lkrb -ldes
#.endif

.include "../../mk/bsd.prefs.mk"

post-extract:
.for FILE in ${EXTRA_FILES}
	${GTAR} xCf ${WRKSRC} ${_DISTDIR}/${FILE}
.endfor

pre-patch:
	@cd ${WRKSRC} ; \
	${PATCH} -sp < prediff.diff ; \
	for i in ftp simult skey ; \
	do \
	    ${PATCH} -sp < rad.$${i}.diff ; \
	done

.include "../../mk/bsd.pkg.mk"
