# $NetBSD: Makefile,v 1.10 1999/04/01 13:38:45 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/04/20 13:19:32 wosch Exp
#

DISTNAME=       kp-0.96
CATEGORIES=	misc tk80
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.0.5:../../x11/tk80

pre-configure:
	for f in `find ${WRKDIR}/. -type f -print|xargs ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done

.include "../../mk/bsd.pkg.mk"
