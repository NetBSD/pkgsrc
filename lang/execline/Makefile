# $NetBSD: Makefile,v 1.5 2021/02/16 14:06:46 schmonz Exp $

DISTNAME=	execline-2.8.0.0
CATEGORIES=	lang shells
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://skarnet.org/software/execline/
COMMENT=	The execline scripting language
LICENSE=	isc

MANPAGES=		v2.8.0.0.1.tar.gz
SITES.${MANPAGES}=	https://github.com/flexibeast/execline-man-pages/archive/

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
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
.include "../../mk/bsd.pkg.mk"
