# $NetBSD: Makefile,v 1.1.1.1 2001/02/07 16:55:01 agc Exp $

DISTNAME=	whois_4.5.2
PKGNAME=	md-whois-4.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.linux.it/~md/software/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/

BUILD_DEPENDS+=	${PERL5}:../../lang/perl5-base

WRKSRC=		${WRKDIR}/whois-4.5.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 ${PREFIX}/man/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
