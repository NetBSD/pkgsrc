# $NetBSD: Makefile,v 1.7 2022/11/28 13:18:23 wiz Exp $

DISTNAME=	rdfind-1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://rdfind.pauldreik.se/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdfind.pauldreik.se/
COMMENT=	Redundant data find
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
