# $NetBSD: Makefile,v 1.17 2003/06/02 01:18:12 jschauma Exp $
# FreeBSD Id: Makefile,v 1.8 1997/04/20 13:19:32 wosch Exp
#

DISTNAME=       kp-0.96
CATEGORIES=	misc tk
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	The Keyboard Practicer, touch-type training program

DEPENDS=	tk>=8.3.2:../../x11/tk

USE_X11=	yes

pre-configure:
	for f in `${FIND} ${WRKDIR}/. -type f -print \
		| ${XARGS} ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f \
			> $$f.pdone && ${MV} $$f.pdone $$f; \
	done

.include "../../mk/bsd.pkg.mk"
