# $NetBSD: Makefile,v 1.10 2026/05/14 16:42:09 ryoon Exp $

DISTNAME=	rdfind-1.5.0
PKGREVISION=	2
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
