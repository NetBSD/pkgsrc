# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:44 rillig Exp $
#

DISTNAME=	cidr-current
PKGNAME=	cidr-2.3.1
CATEGORIES=	net
MASTER_SITES=	http://home.netcom.com/~naym/cidr/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://home.netcom.com/~naym/cidr.html
COMMENT=	RFC 1878 subnet calculator / helper

WRKSRC=		${WRKDIR}/cidr-2.3

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
