# $NetBSD: Makefile,v 1.11 2005/03/30 20:06:59 reed Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	Powerful DNS query and testing tool

INSTALLATION_DIRS=	bin man/man1
NO_CONFIGURE =	yes

MAKEFILE=	Makefile.BSD

MAKE_FLAGS+=	__NetBSD__=1

.include "../../mk/bsd.pkg.mk"
