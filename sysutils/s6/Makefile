# $NetBSD: Makefile,v 1.6 2021/02/17 19:31:00 schmonz Exp $

DISTNAME=	s6-2.10.0.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://skarnet.org/software/s6/
COMMENT=	The s6 supervision suite
LICENSE=	isc

MANPAGES=		v2.10.0.2.1.tar.gz
SITES.${MANPAGES}=	https://github.com/flexibeast/s6-man-pages/archive/

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/execline
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7

.PHONY: do-install-manpages
post-install: do-install-manpages
do-install-manpages:
	cd ${WRKDIR}/${PKGBASE}-man-pages-*; for i in 1 7; do \
		for j in *.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

BUILDLINK_API_DEPENDS.skalibs+=		skalibs>=2.10.0.2
.include "../../devel/skalibs/buildlink3.mk"
BUILDLINK_API_DEPENDS.execline+=	execline>=2.7.0.1
.include "../../lang/execline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
