# $NetBSD: Makefile,v 1.7 1998/04/15 10:38:11 agc Exp $
# FreeBSD Id: Makefile,v 1.29 1996/12/20 23:46:22 ache Exp 
#

DISTNAME=       tracker-5.3
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.ens.fr/pub/dmi/users/espie/beta/
EXTRACT_SUFX=   .tgz

# FreeBSD maintainer
MAINTAINER=     ache@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

RESTRICTED=     "Non-redistributable beta"
MIRROR_DISTFILE=	no

WRKSRC=         ${WRKDIR}/tracker
MAKE_FLAGS=     MACHINE=netbsd CC=${CC} INSTALL="${INSTALL}" \
		INST_BIN_OPT="-c -s -m ${BINMODE} -o ${BINOWN} -g ${BINGRP}" \
		INST_MAN_OPT="-c -m 644 -o ${BINOWN} -g ${BINGRP}" \
		COMPRESSION_FILE=${PREFIX}/etc/compression_methods \
		-f

post-install:
	cd ${WRKSRC}/Docs && \
	makeinfo --no-split tracker.texinfo -o tracker.info && \
	${CP} tracker.info ${PREFIX}/info && \
	install-info ${PREFIX}/info/tracker.info ${PREFIX}/info/dir && \
	${RM} -f tracker.info *.orig
	-${MKDIR} ${PREFIX}/share/doc/tracker
	${CP} -R ${WRKSRC}/Docs/* ${PREFIX}/share/doc/tracker

.include "../../mk/bsd.pkg.mk"
