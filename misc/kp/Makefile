# New ports collection makefile for:    kp
# Version required:     0.96
# Date created:         8 May 1995
# Whom:                 asami
#
# $NetBSD: Makefile,v 1.3 1998/01/24 21:10:16 hubertf Exp $
# FreeBSD Id: Makefile,v 1.8 1997/04/20 13:19:32 wosch Exp
#

DISTNAME=       kp-0.96
CATEGORIES=	misc tk80
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	asami@FreeBSD.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

MAN1=		kp.1

pre-configure:
	find ${WRKDIR} -type f -print|xargs ${GREP} -l '/usr/local' > ${WRKDIR}/prefix-list
	for f in `cat ${WRKDIR}/prefix-list`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	${RM} ${WRKDIR}/prefix-list

.include <bsd.port.mk>
