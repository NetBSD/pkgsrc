# $NetBSD: Makefile,v 1.6 2005/10/12 07:10:57 seb Exp $
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
MAKE_ENV+=	LIBS="${LIBS}"

.include "../../mk/bsd.pkg.mk"
