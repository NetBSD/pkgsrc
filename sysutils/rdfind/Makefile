# $NetBSD: Makefile,v 1.5 2020/01/26 17:32:11 rillig Exp $

DISTNAME=	rdfind-1.4.1
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
