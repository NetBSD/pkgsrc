# $NetBSD: Makefile,v 1.8 2020/10/26 09:45:17 schmonz Exp $

DISTNAME=		fdtools-2020.05.04
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://code.dogmap.org./fdtools/
COMMENT=		Manipulate file descriptor properties from shell scripts
LICENSE=		gnu-gpl-v2

DJB_RESTRICTED=		no

WRKSRC=			${WRKDIR}/misc/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES

CPPFLAGS+=		-I ${PREFIX:Q}/include
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

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
