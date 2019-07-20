# $NetBSD: Makefile,v 1.3 2019/07/20 22:46:51 wiz Exp $

DISTNAME=	rdfind-1.3.4
PKGREVISION=	2
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
