# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:38 veego Exp $

DISTNAME=	Net_SSLeay.pm-1.08
PKGNAME=	p5-Net-SSLeay-1.08
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bacus.pt/Net_SSLeay/index.html
COMMENT=	perl5 module for using OpenSSL

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist
MAKE_PARAMS=	${SSLBASE}

USE_OPENSSL_VERSION=	OPENSSL_VERSION_096A

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
