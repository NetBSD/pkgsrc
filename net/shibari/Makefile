# $NetBSD: Makefile,v 1.1 2023/12/29 16:55:09 schmonz Exp $

DISTNAME=		shibari-0.0.1.0
CATEGORIES=		net
MASTER_SITES=		https://skarnet.org/software/shibari/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES_DIST}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/shibari/
COMMENT=		Collection of DNS tools for Unix systems
LICENSE=		isc

# man-pages version is usually not exactly in-sync with PKGVERSION_NOREV
MANPAGES_VERSION=	0.0.1.0.1
MANPAGES_DIST=		shibari-man-pages-${MANPAGES_VERSION}.tar.gz
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/shibari-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps

INSTALLATION_DIRS+=	${PKGMANDIR}/man8

.PHONY: do-install-manpages
post-install: do-install-manpages
do-install-manpages:
	cd ${WRKDIR}/${PKGBASE}-man-pages-*; for i in 8; do \
		for j in man$$i/*.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

.include "../../devel/skalibs/buildlink3.mk"
.include "../../net/s6-dns/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
