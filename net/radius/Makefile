# $NetBSD: Makefile,v 1.9 1999/04/24 23:53:33 tron Exp $
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
INSTALL_TARGET=	man-install install util-install config-install
MESSAGE_FILE=   ${WRKDIR}/MESSAGE
NO_WRKSUBDIR=	yes

CFLAGS+=	-DHAVE_SETVBUF -DNOSHADOW
MAKE_ENV+=	RADLIBS="${RADLIBS} -lskey" LIBS=-lcrypt \
		GNUZIP="`${ECHO} ${GZIP_CMD} | ${AWK} '{print $$1}'`" \
		INSTALL="${INSTALL} -c"

# XXX Kerberos IV support is known to be broken.
#.if exists(/usr/lib/libkrb.a) && \
#    (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
#CFLAGS+=	-DM_KERB -I/usr/include/kerberosIV
#RADLIBS=	-lkrb -ldes
#.endif

.include "../../mk/bsd.prefs.mk"

pre-patch:
.for FILE in prediff rad.ftp rad.simult rad.skey
	@cd ${WRKSRC}; ${PATCH} -sp <${FILE}.diff
.endfor

post-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
	  >${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"
