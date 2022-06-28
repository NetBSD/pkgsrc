# $NetBSD: Makefile,v 1.18 2022/06/28 11:34:31 wiz Exp $

DISTNAME=	Net-SMTP_auth-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-SMTP_auth
COMMENT=	Perl module adding SMTP AUTH support to Net::SMTP module

PERL5_PACKLIST=	auto/Net/SMTP_auth/.packlist

# Also depends on MIME::Base64 and Net::SMTP bundled with perl
DEPENDS+=	p5-Authen-SASL>=2.03:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-HMAC>=1.0:../../security/p5-Digest-HMAC

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
