# $NetBSD: Makefile,v 1.10 2016/04/01 11:45:27 jperkin Exp $
#

DISTNAME=	httptunnel-3.3
CATEGORIES=	net
MASTER_SITES=	http://www.nocrew.org/software/httptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nocrew.org/software/httptunnel.html
COMMENT=	Encapsulate TCP/IP connections in HTTP requests
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
