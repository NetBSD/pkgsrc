# $NetBSD: Makefile,v 1.13 2000/08/30 20:49:15 jwise Exp $
# FreeBSD Id: Makefile,v 1.8 1997/04/20 13:19:32 wosch Exp
#

DISTNAME=       kp-0.96
CATEGORIES=	misc tk
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.3.2:../../x11/tk

USE_X11=	yes

pre-configure:
	for f in `${FIND} ${WRKDIR}/. -type f -print \
		| xargs ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f \
			> $$f.pdone && ${MV} $$f.pdone $$f; \
	done

.include "../../mk/bsd.pkg.mk"
