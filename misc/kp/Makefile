# $NetBSD: Makefile,v 1.21 2005/03/24 21:12:57 wiz Exp $

DISTNAME=       kp-0.96
CATEGORIES=	misc tk
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	tech-pkg@NetBSD.org
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
