# $NetBSD: Makefile,v 1.6 1998/04/24 09:20:36 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/04/20 13:19:32 wosch Exp
#

DISTNAME=       kp-0.96
CATEGORIES=	misc tk80
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	packages@netbsd.org

RUN_DEPENDS=	wish8.0:../../x11/tk80

MAN1=		kp.1

pre-configure:
	find ${WRKDIR} -type f -print|xargs ${GREP} -l '/usr/local' > ${WRKDIR}/prefix-list
	for f in `cat ${WRKDIR}/prefix-list`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	${RM} ${WRKDIR}/prefix-list

.include "../../mk/bsd.pkg.mk"
