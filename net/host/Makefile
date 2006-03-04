# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:19 jlam Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	Powerful DNS query and testing tool

INSTALLATION_DIRS=	bin man/man1
NO_CONFIGURE =	yes

MAKEFILE=	Makefile.BSD

MAKE_FLAGS+=	__NetBSD__=1

.include "../../mk/bsd.pkg.mk"
