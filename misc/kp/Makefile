# New ports collection makefile for:    kp
# Version required:     0.96
# Date created:         8 May 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.2 1997/10/27 00:16:42 hubertf Exp $
#

DISTNAME=       kp-0.96
CATEGORIES=	misc tk80
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	asami@FreeBSD.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

MAN1=		kp.1

pre-configure:
	find ${WRKDIR} -type f -print|xargs grep -l '/usr/local' > ${WRKDIR}/prefix-list
	for f in `cat ${WRKDIR}/prefix-list`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && mv $$f.pdone $$f; \
	done
	rm ${WRKDIR}/prefix-list

.include <bsd.port.mk>
