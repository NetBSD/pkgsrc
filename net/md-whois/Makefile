# $NetBSD: Makefile,v 1.3 2001/03/27 03:20:11 hubertf Exp $

DISTNAME=	whois_4.5.2
PKGNAME=	md-whois-4.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.linux.it/~md/software/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT=	Improved whois client

BUILD_DEPENDS+=	perl-5.*:../../lang/perl5

WRKSRC=		${WRKDIR}/whois-4.5.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 ${PREFIX}/man/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
