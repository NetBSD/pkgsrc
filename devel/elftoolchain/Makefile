# $NetBSD: Makefile,v 1.10 2016/03/09 21:34:21 tnn Exp $

DISTNAME=	elftoolchain-0.5.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=elftoolchain/${DISTNAME}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://elftoolchain.sourceforge.net/
COMMENT=	Compilation tools (nm, ar, as, ld, etc.) for the ELF object format
LICENSE=	modified-bsd

CONFLICTS=	libelf-[0-9]*

MAKE_JOBS_SAFE=	no

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		m4
MAKE_ENV+=		${BSD_MAKE_ENV}
MAKE_FLAGS+=		MKPROFILE=yes

CWARNFLAGS.clang=	-Wno-error=missing-noreturn \
			-Wno-error=constant-logical-operand \
			-Wno-error=conversion -Wno-error=cast-qual
MAKE_FLAGS+=		CWARNFLAGS.clang=${CWARNFLAGS.clang:Q}

INSTALLATION_DIRS=	bin lib
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/cat1 ${PKGMANDIR}/html1
INSTALLATION_DIRS+=	${PKGMANDIR}/man3 ${PKGMANDIR}/cat3 ${PKGMANDIR}/html3
INSTALLATION_DIRS+=	${PKGMANDIR}/man5 ${PKGMANDIR}/cat5 ${PKGMANDIR}/html5

.include "../../mk/bsd.pkg.mk"
