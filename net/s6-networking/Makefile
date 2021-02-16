# $NetBSD: Makefile,v 1.8 2021/02/16 14:07:52 schmonz Exp $

DISTNAME=	s6-networking-2.4.1.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://skarnet.org/software/s6-networking/
COMMENT=	Suite of small networking utilities
LICENSE=	isc

MANPAGES=		v2.4.0.0.2.tar.gz
SITES.${MANPAGES}=	https://github.com/flexibeast/s6-networking-man-pages/archive/

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--enable-absolute-paths

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7

.include "options.mk"

.PHONY: do-install-manpages
post-install: do-install-manpages
do-install-manpages:
	cd ${WRKDIR}/${PKGBASE}-man-pages-*; for i in 1 7; do \
		for j in *.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

BUILDLINK_API_DEPENDS.skalibs+=	skalibs>=2.10.0.2
.include "../../devel/skalibs/buildlink3.mk"
BUILDLINK_API_DEPENDS.s6-dns+=	s6-dns>=2.3.5.0
.include "../../net/s6-dns/buildlink3.mk"
BUILDLINK_API_DEPENDS.s6+=	s6>=2.10.0.2
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
