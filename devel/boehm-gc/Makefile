# $NetBSD: Makefile,v 1.14 2000/03/16 11:59:16 pooka Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=		gc5.0alpha3
PKGNAME=		boehm-gc-5.0a3
CATEGORIES=		devel
MASTER_SITES=		http://reality.sgi.com/boehm_mti/gc_source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://reality.sgi.com/boehm_mti/gc.html

WRKSRC=			${WRKDIR}/gc
ALL_TARGET=		BSD-pkg-all
INSTALL_TARGET=		BSD-pkg-install
MAKE_ENV+=		CP="${CP}" INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_MAN="${INSTALL_MAN}"
USE_GMAKE=		yes

.include "../../mk/bsd.prefs.mk"
.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS=	-u
.endif

post-extract:
	${MV} ${WRKSRC}/gc.man ${WRKSRC}/gc.man.in

pre-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${WRKSRC}/gc.man.in \
		> ${WRKSRC}/gc.man

.include "../../mk/bsd.pkg.mk"
