# $NetBSD: Makefile,v 1.11 2026/05/15 11:15:36 abs Exp $

DISTNAME=	rdfind-1.8.0
CATEGORIES=	sysutils
MASTER_SITES=	https://rdfind.pauldreik.se/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdfind.pauldreik.se/
COMMENT=	Redundant data find
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
