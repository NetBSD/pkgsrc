# $NetBSD: Makefile,v 1.14 1999/12/05 22:46:42 tron Exp $
#
# Tempted to install another radius package?
#
#	Please consider e-mailing ${MAINTAINER} first with your concerns.
#	It would be nice to just fold new extensions into this code, and
#	avoid a myriad of incompatible radiusd incarnations.

DISTNAME=	radius.3.6B
PKGNAME=	${DISTNAME:S/./-/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radius/releases/ \
		http://www.mr.net/~bradley/radius/
DISTFILES=	${DISTNAME}.basic.tar.gz \
		${DISTNAME}-skey.tar.gz \
		${DISTNAME}-ftp.tar \
		${DISTNAME}-simultd.tar

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.merit.edu/aaa/

DIST_SUBDIR=	radius

CFLAGS+=	-DHAVE_SETVBUF -DNOSHADOW
DECOMPRESS_CMD=	${GZCAT} -f
INSTALL_TARGET=	man-install install util-install config-install
MAKE_ENV+=	RADLIBS="${RADLIBS} -lskey" LIBS=-lcrypt \
		GNUZIP="`${ECHO} ${GZIP_CMD} | ${AWK} '{print $$1}'`" \
		INSTALL="${INSTALL} -c"
MESSAGE_FILE=   ${WRKDIR}/MESSAGE
WRKSRC=		${WRKDIR}

# XXX Kerberos IV support is known to be broken.
#.if defined(KERBEROS) && ${KERBEROS} == 4
#USE_KERBEROS=	yes
#CFLAGS+=	-DM_KERB -I/usr/include/kerberosIV
#RADLIBS=	-lkrb -ldes
#.endif

.include "../../mk/bsd.prefs.mk"

pre-patch:
.for FILE in prediff rad.simult rad.ftp rad.skey
	@cd ${WRKSRC} && \
	${SED} -e 's#^--- ${DISTNAME}.patched/#--- #' ${FILE}.diff | \
	${PATCH} -s
.endfor

post-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
	  >${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"
