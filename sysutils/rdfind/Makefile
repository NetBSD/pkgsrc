# $NetBSD: Makefile,v 1.9 2026/02/06 10:05:57 wiz Exp $

DISTNAME=	rdfind-1.5.0
PKGREVISION=	1
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
