# New ports collection makefile for:    tracker
# Version required:     5.3
# Date created:         2 Oct 1994
# Whom:                 swallace
#
# $NetBSD: Makefile,v 1.3 1998/01/08 17:28:13 agc Exp $
# FreeBSD Id: Makefile,v 1.29 1996/12/20 23:46:22 ache Exp 
#

DISTNAME=       tracker-5.3
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.ens.fr/pub/dmi/users/espie/beta/
EXTRACT_SUFX=   .tgz

# FreeBSD maintainer
MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=     "Non-redistributable beta"

WRKSRC=         ${WRKDIR}/tracker
MAKE_FLAGS=     MACHINE=netbsd CC=$(CC) INSTALL="$(INSTALL)" \
		INST_BIN_OPT="-c -s -m $(BINMODE) -o $(BINOWN) -g $(BINGRP)" \
		INST_MAN_OPT="-c -m 644 -o $(BINOWN) -g $(BINGRP)" \
		COMPRESSION_FILE=$(PREFIX)/etc/compression_methods \
		-f

post-install:
	cd ${WRKSRC}/Docs && \
	makeinfo --no-split tracker.texinfo -o tracker.info && \
	gzip -f tracker.info && \
	$(INSTALL_MAN) tracker.info.gz ${PREFIX}/info && \
	rm -f tracker.info.gz *.orig
	-${MKDIR} ${PREFIX}/share/doc/tracker
	cp -R ${WRKSRC}/Docs/* ${PREFIX}/share/doc/tracker

.include <bsd.port.mk>
