# $NetBSD: Makefile,v 1.16 2004/04/25 08:39:50 snj Exp $
#
# XXX do not use -- see ../netatalk instead

DISTNAME=	netatalk-1.4b2+asun2.1.3
PKGNAME=	netatalk-asun-2.1.3
PKGREVISION=	6
CATEGORIES=	net print
MASTER_SITES=	ftp://ftp.cobaltnet.com/pub/users/asun/release/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.u.washington.edu/public/asun/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/netatalk/
COMMENT=	Netatalk appletalk file and print services, enhanced by Adrian Sun

CONFLICTS=	netatalk-[0-9]*
CONFLICTS+=	netatalk-umich-[0-9]*

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

MAKE_ENV+=		ETCDIR="${PKG_SYSCONFDIR}"
MAKE_ENV+=		RCDIR="${PREFIX}/etc/rc.d"

PKG_SYSCONFSUBDIR=	netatalk

RCD_SCRIPTS=		netatalk

post-extract:
		@${MV} ${WRKSRC}/man/man8/papd.8 ${WRKSRC}/man/man8/papd.tbl

post-build:
		tbl ${WRKSRC}/man/man8/papd.tbl > ${WRKSRC}/man/man8/papd.8

.include "../../mk/bsd.pkg.mk"
