# $NetBSD: Makefile,v 1.8 2001/12/19 06:45:50 martti Exp $

DISTNAME=	Net_SSLeay.pm-1.12
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/}
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@shellhung.org
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
