# $NetBSD: Makefile,v 1.9 2001/05/09 14:12:40 fredb Exp $

DISTNAME=	netatalk-1.4b2+asun2.1.3
PKGNAME=	netatalk-asun-2.1.3nb4
CATEGORIES=	net print
MASTER_SITES=   ftp://ftp.cobaltnet.com/pub/users/asun/release/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.u.washington.edu/public/asun/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/netatalk/
COMMENT=	Netatalk appletalk file and print services, enhanced by Adrian Sun

CONFLICTS=	netatalk-[0-9]*
CONFLICTS+=	netatalk-umich-*

post-extract:
		@${MV} ${WRKSRC}/man/man8/papd.8 ${WRKSRC}/man/man8/papd.tbl

post-build:
		tbl ${WRKSRC}/man/man8/papd.tbl > ${WRKSRC}/man/man8/papd.8

.include "../../mk/bsd.pkg.mk"
