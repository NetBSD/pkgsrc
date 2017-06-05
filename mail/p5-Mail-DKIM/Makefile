# $NetBSD: Makefile,v 1.31 2017/06/05 14:24:06 ryoon Exp $
#

DISTNAME=		Mail-DKIM-0.40
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Mail-DKIM/
COMMENT=		Perl5 module for DKIM-based mail-signing and -verifying
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-OpenSSL-RSA>=0.27:../../security/p5-Crypt-OpenSSL-RSA
#DEPENDS+=		{perl>=5.9.3,p5-Digest-SHA-[0-9]*}:../../security/p5-Digest-SHA
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
#DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mail/DKIM/.packlist

REPLACE_PERL+=		lib/Mail/DKIM.pm
REPLACE_PERL+=		lib/Mail/DKIM/*.pm
REPLACE_PERL+=		lib/Mail/DKIM/Algorithm/*.pm
REPLACE_PERL+=		lib/Mail/DKIM/Canonicalization/*.pm
REPLACE_PERL+=		sample_mime_lite.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
