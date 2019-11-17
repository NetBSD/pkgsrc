# $NetBSD: Makefile,v 1.4 2019/11/17 12:38:52 mef Exp $

DISTNAME=	rdfind-1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://rdfind.pauldreik.se/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rdfind.pauldreik.se/
COMMENT=	Redundant data find
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
