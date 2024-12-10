# $NetBSD: Makefile,v 1.17 2024/12/10 14:32:04 schmonz Exp $

DISTNAME=		fdtools-2024.12.07
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://code.dogmap.org./fdtools/
COMMENT=		Manipulate file descriptor properties from shell scripts
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/misc/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES

CPPFLAGS+=		-I ${PREFIX:Q}/include
LDFLAGS+=		-L ${PREFIX:Q}/lib/skalibs
LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

do-configure:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-compile/defaults/package_home
	${ECHO} ${PREFIX}/lib/skalibs/sysdeps > ${WRKSRC}/conf-compile/defaults/depend_skalibs_sysdeps

do-install:
	cd ${WRKSRC}/command; \
	for i in *; do \
		${INSTALL_PROGRAM} $${i} ${DESTDIR}${PREFIX}/bin; \
	done
	cd ${WRKSRC}/man; for i in 1 8; do \
		for j in man$$i/*.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

SKALIBS_TOLERATE_TARGET_SKEW=	no
.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
