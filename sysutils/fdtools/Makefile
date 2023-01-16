# $NetBSD: Makefile,v 1.16 2023/01/16 21:49:55 schmonz Exp $

DISTNAME=		fdtools-2021.04.30
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://code.dogmap.org./fdtools/
COMMENT=		Manipulate file descriptor properties from shell scripts
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/misc/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES

CPPFLAGS+=		-I ${PREFIX:Q}/include \
			-Dtain_t=tain
LDFLAGS+=		-L ${PREFIX:Q}/lib/skalibs
LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS+=	bin

do-configure:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-compile/defaults/package_home
	${ECHO} ${PREFIX}/lib/skalibs/sysdeps > ${WRKSRC}/conf-compile/defaults/depend_skalibs_sysdeps

do-install:
	cd ${WRKSRC}/command; \
	for i in *; do \
	  ${INSTALL_PROGRAM} $${i} ${DESTDIR}${PREFIX}/bin; \
	done

SKALIBS_TOLERATE_TARGET_SKEW=	no
.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
