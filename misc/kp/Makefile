# $NetBSD: Makefile,v 1.27 2007/02/22 19:26:49 wiz Exp $

DISTNAME=	kp-0.96
PKGREVISION=	1
CATEGORIES=	misc tk
MASTER_SITES=	ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The Keyboard Practicer, touch-type training program

DEPENDS+=	tk>=8.3.2:../../x11/tk

pre-configure:
	for f in `${FIND} ${WRKDIR}/. -type f -print \
		| ${XARGS} ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f \
			> $$f.pdone && ${MV} $$f.pdone $$f; \
	done

.include "../../mk/bsd.pkg.mk"
