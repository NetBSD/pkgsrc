# $NetBSD: Makefile,v 1.29 2012/10/08 09:57:28 asau Exp $

DISTNAME=	kp-0.96
PKGREVISION=	1
CATEGORIES=	misc tk
MASTER_SITES=	ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The Keyboard Practicer, touch-type training program

DEPENDS+=	tk>=8.3.2:../../x11/tk

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			KPMANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

pre-configure:
	for f in `${FIND} ${WRKDIR}/. -type f -print \
		| ${XARGS} ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f \
			> $$f.pdone && ${MV} $$f.pdone $$f; \
	done

.include "../../mk/bsd.pkg.mk"
