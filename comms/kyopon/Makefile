# $NetBSD: Makefile,v 1.13 2013/09/10 14:14:02 joerg Exp $

DISTNAME=		kyopon-0.5
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=		Tool to manipulate data of Kyocera PHS handset

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

USE_BSD_MAKEFILE=	yes

CWARNFLAGS.clang=	-Wno-error=pointer-sign
MAKE_ENV+=		CWARNFLAGS.clang=${CWARNFLAGS.clang:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
