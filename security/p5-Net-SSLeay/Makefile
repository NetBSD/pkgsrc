# $NetBSD: Makefile,v 1.17 2002/09/27 09:33:08 shell Exp $

DISTNAME=	Net_SSLeay.pm-1.20
PKGNAME=	p5-${DISTNAME:S/Net_/Net-/:S/.pm//}
SVR4_PKGNAME=	p5nsl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://symlabs.com/Net_SSLeay/
COMMENT=	perl5 module for using OpenSSL

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SSLeay/.packlist

USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096G}

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
