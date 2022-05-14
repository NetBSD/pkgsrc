# $NetBSD: Makefile,v 1.8 2022/05/14 15:14:41 schmonz Exp $

DISTNAME=	s6-portable-utils-2.2.4.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://www.skarnet.org/software/s6-portable-utils/
COMMENT=	Tiny portable generic utilties
LICENSE=	isc

MANPAGES=		v2.2.4.0.1.tar.gz
SITES.${MANPAGES}=	${MASTER_SITE_GITHUB:=flexibeast/s6-portable-utils-man-pages/archive/}

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.PHONY: do-install-manpages
post-install: do-install-manpages
do-install-manpages:
	cd ${WRKDIR}/${PKGBASE}-man-pages-*; for i in 1; do \
		for j in man$$i/*.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
