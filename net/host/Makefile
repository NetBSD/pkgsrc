# $NetBSD: Makefile,v 1.13 2006/09/09 02:43:11 obache Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	Powerful DNS query and testing tool

INSTALLATION_DIRS=	bin man/man1
NO_CONFIGURE =	yes

MAKE_FILE=	Makefile.BSD

MAKE_FLAGS+=	__NetBSD__=1

.include "../../mk/bsd.pkg.mk"
