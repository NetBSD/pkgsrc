# $NetBSD: Makefile,v 1.9 2005/03/26 05:19:20 christos Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	A powerful DNS query and testing tool

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE =	yes
NO_PATCH =	yes

MAKEFILE=	Makefile.BSD

MAKE_FLAGS+=	__NetBSD__=1

.include "../../mk/bsd.pkg.mk"
