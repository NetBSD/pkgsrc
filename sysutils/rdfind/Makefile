# $NetBSD: Makefile,v 1.6 2020/05/22 10:56:40 adam Exp $

DISTNAME=	rdfind-1.4.1
PKGREVISION=	1
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
