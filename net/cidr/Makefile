# $NetBSD: Makefile,v 1.11 2010/02/11 20:32:49 joerg Exp $
#

DISTNAME=	cidr-current
PKGNAME=	cidr-2.3.1
CATEGORIES=	net
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://home.netcom.com/~naym/cidr.html
COMMENT=	RFC 1878 subnet calculator / helper

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/cidr-2.3

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
