# $NetBSD: Makefile,v 1.4 2001/04/30 04:16:10 jlam Exp $

DISTNAME=	whois_4.5.2
PKGNAME=	md-whois-4.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.linux.it/~md/software/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT=	Improved whois client

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

WRKSRC=		${WRKDIR}/whois-4.5.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 ${PREFIX}/man/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
