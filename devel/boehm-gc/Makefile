# $NetBSD: Makefile,v 1.17 2000/11/16 11:16:02 abs Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=		gc5.3
PKGNAME=		boehm-gc-5.3
CATEGORIES=		devel
MASTER_SITES=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/

USE_GMAKE=		# defined

WRKSRC=			${WRKDIR}/gc
MAKE_ENV+=		CP="${CP}" INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_MAN="${INSTALL_MAN}"

ALL_TARGET=		BSD-pkg-all
INSTALL_TARGET=		BSD-pkg-install

.include "../../mk/bsd.prefs.mk"
.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS=	-u
.endif

.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-D__MIPSEL__
.endif

post-extract:
	${MV} ${WRKSRC}/gc.man ${WRKSRC}/gc.man.in

pre-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${WRKSRC}/gc.man.in \
		> ${WRKSRC}/gc.man

.include "../../mk/bsd.pkg.mk"
