# $NetBSD: Makefile,v 1.17 2023/11/11 11:57:20 schmonz Exp $

DISTNAME=	s6-networking-2.6.0.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANPAGES_DIST}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://skarnet.org/software/s6-networking/
COMMENT=	Suite of small networking utilities
LICENSE=	isc

# man-pages version is usually not exactly in-sync with PKGVERSION_NOREV
MANPAGES_VERSION=	2.6.0.0.1
MANPAGES_DIST=		s6-networking-man-pages-${MANPAGES_VERSION}.tar.gz
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/s6-networking-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--enable-absolute-paths

INSTALLATION_DIRS+=	${PKGMANDIR}/man7 ${PKGMANDIR}/man8

.include "options.mk"

.PHONY: do-install-manpages
post-install: do-install-manpages
do-install-manpages:
	cd ${WRKDIR}/${PKGBASE}-man-pages-*; for i in 7 8; do \
		for j in man$$i/*.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

.include "../../devel/skalibs/buildlink3.mk"
.include "../../net/s6-dns/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
