# $NetBSD: Makefile,v 1.2 2001/09/27 07:29:39 jlam Exp $

DISTNAME=	Net_SSLeay.pm-1.08
PKGNAME=	p5-Net-SSLeay-1.08
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
