# $NetBSD: Makefile,v 1.12 1999/08/18 09:28:02 agc Exp $
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
WRKSRC=		${WRKDIR}

CFLAGS+=	-DHAVE_SETVBUF -DNOSHADOW
MAKE_ENV+=	RADLIBS="${RADLIBS} -lskey" LIBS=-lcrypt \
		GNUZIP="`${ECHO} ${GZIP_CMD} | ${AWK} '{print $$1}'`" \
		INSTALL="${INSTALL} -c"

# XXX Kerberos IV support is known to be broken.
#.if defined(USE_KERBEROS4)
#CFLAGS+=	-DM_KERB -I/usr/include/kerberosIV
#RADLIBS=	-lkrb -ldes
#RESTRICTED=	uses Kerberos encryption code
#.endif

BUILD_DEFS+=	USE_KERBEROS4

.include "../../mk/bsd.prefs.mk"

pre-patch:
.for FILE in prediff rad.ftp rad.simult rad.skey
	@cd ${WRKSRC}; ${PATCH} -sp <${FILE}.diff
.endfor

post-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
	  >${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"
