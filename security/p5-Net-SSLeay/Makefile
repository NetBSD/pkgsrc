# $NetBSD: Makefile,v 1.6 2001/12/10 15:22:36 martti Exp $

DISTNAME=	Net_SSLeay.pm-1.10
PKGNAME=	p5-Net-SSLeay-1.10
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bacus.pt/Net_SSLeay/index.html
COMMENT=	perl5 module for using OpenSSL

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist
MAKE_PARAMS=		${BUILDLINK_DIR}

USE_OPENSSL_VERSION=	OPENSSL_VERSION_096A

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../lang/perl5/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
