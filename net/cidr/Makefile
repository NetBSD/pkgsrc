# $NetBSD: Makefile,v 1.5 2004/11/03 10:57:54 grant Exp $
#

DISTNAME=	cidr-current
PKGNAME=	cidr-2.3.1
CATEGORIES=	net
MASTER_SITES=	http://home.netcom.com/~naym/cidr/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://home.netcom.com/~naym/cidr.html
COMMENT=	RFC 1878 subnet calculator / helper

WRKSRC=		${WRKDIR}/cidr-2.3

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS="${LIBS}"

.include "../../mk/bsd.pkg.mk"
