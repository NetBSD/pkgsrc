# $NetBSD: Makefile,v 1.9 2021/04/26 15:05:30 schmonz Exp $

DISTNAME=	s6-networking-2.4.1.1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://skarnet.org/software/s6-networking/
COMMENT=	Suite of small networking utilities
LICENSE=	isc

MANPAGES=		v2.4.1.1.1.tar.gz
SITES.${MANPAGES}=	${MASTER_SITE_GITHUB:=flexibeast/s6-networking-man-pages/archive/}

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

.include "../../devel/skalibs/buildlink3.mk"
.include "../../net/s6-dns/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
