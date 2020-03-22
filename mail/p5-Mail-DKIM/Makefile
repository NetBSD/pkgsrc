# $NetBSD: Makefile,v 1.44 2020/03/22 20:38:01 rillig Exp $

DISTNAME=		Mail-DKIM-0.55
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Mail-DKIM
COMMENT=		Perl5 module for DKIM-based mail-signing and -verifying
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-OpenSSL-RSA>=0.27:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
DEPENDS+=		p5-Mail-AuthenticationResults>=1.20180215:../../mail/p5-Mail-AuthenticationResults
# TEST_DEPENDS
BUILD_DEPENDS+=		p5-Net-DNS-Resolver-Mock-[0-9]*:../../net/p5-Net-DNS-Resolver-Mock
BUILD_DEPENDS+=		p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mail/DKIM/.packlist

REPLACE_PERL+=		lib/Mail/DKIM.pm
REPLACE_PERL+=		lib/Mail/DKIM/*.pm
REPLACE_PERL+=		lib/Mail/DKIM/Algorithm/*.pm
REPLACE_PERL+=		lib/Mail/DKIM/Canonicalization/*.pm
REPLACE_PERL+=		scripts/sample_mime_lite.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
