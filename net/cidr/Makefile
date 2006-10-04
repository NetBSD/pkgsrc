# $NetBSD: Makefile,v 1.10 2006/10/04 21:53:16 wiz Exp $
#

DISTNAME=	cidr-current
PKGNAME=	cidr-2.3.1
CATEGORIES=	net
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://home.netcom.com/~naym/cidr.html
COMMENT=	RFC 1878 subnet calculator / helper

WRKSRC=		${WRKDIR}/cidr-2.3

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
