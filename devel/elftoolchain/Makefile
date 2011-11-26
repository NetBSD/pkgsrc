# $NetBSD: Makefile,v 1.3 2011/11/26 15:50:27 dholland Exp $

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

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

USE_BSD_MAKEFILE=	yes
MAKE_ENV+=		${BSD_MAKE_ENV}

INSTALLATION_DIRS=	bin lib
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/cat1 ${PKGMANDIR}/html1
INSTALLATION_DIRS+=	${PKGMANDIR}/man3 ${PKGMANDIR}/cat3 ${PKGMANDIR}/html3
INSTALLATION_DIRS+=	${PKGMANDIR}/man5 ${PKGMANDIR}/cat5 ${PKGMANDIR}/html5

.include "../../mk/bsd.pkg.mk"
