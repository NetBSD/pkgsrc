# $NetBSD: Makefile,v 1.12 2001/11/29 01:12:43 hubertf Exp $

DISTNAME=	netatalk-1.4b2+asun2.1.3
PKGNAME=	netatalk-asun-2.1.3
PKGREVISION=	5
CATEGORIES=	net print
MASTER_SITES=   ftp://ftp.cobaltnet.com/pub/users/asun/release/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.u.washington.edu/public/asun/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/netatalk/
COMMENT=	Netatalk appletalk file and print services, enhanced by Adrian Sun

CONFLICTS=	netatalk-[0-9]*
CONFLICTS+=	netatalk-umich-[0-9]*

post-extract:
		@${MV} ${WRKSRC}/man/man8/papd.8 ${WRKSRC}/man/man8/papd.tbl

post-build:
		tbl ${WRKSRC}/man/man8/papd.tbl > ${WRKSRC}/man/man8/papd.8

.include "../../mk/bsd.pkg.mk"
