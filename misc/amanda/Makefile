# $NetBSD: Makefile,v 1.4 1997/10/15 16:54:39 agc Exp $
# New ports collection makefile for:	amanda
# Version required:			2.3.0
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=	amanda-2.3.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=	gpalmer@FreeBSD.ORG

PATCH_STRIP=	
MAN8=		amanda.8 amadmin.8 amcheck.8 amcleanup.8 amdump.8 \
		amflush.8 amlabel.8 amrestore.8  amtape.8

pre-configure:
	echo "${CFLAGS}" > /tmp/build-ports-misc-amanda-cflags
	find ${WRKDIR} -type f -print|xargs grep -l '/usr/local' > ${WRKDIR}/prefix-list
	for f in `cat ${WRKDIR}/prefix-list`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && mv $$f.pdone $$f; \
	done
	rm ${WRKDIR}/prefix-list

post-install:
	mkdir -p ${PREFIX}/share/examples/amanda
	cp -R ${WRKSRC}/example/* ${PREFIX}/share/examples/amanda

.include <bsd.port.mk>
