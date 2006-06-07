# $NetBSD: Makefile,v 1.2 2006/06/07 21:30:10 heinz Exp $
#

DISTNAME=		Mail-DKIM-0.17
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mdk
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Mail-DKIM/
COMMENT=		Perl5 module for DKIM-based mail-signing and -verifying

DEPENDS+=		p5-Crypt-OpenSSL-Bignum-[0-9]*:../../security/p5-Crypt-OpenSSL-Bignum
DEPENDS+=		p5-Crypt-OpenSSL-RSA-[0-9]*:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=		p5-Crypt-RSA-[0-9]*:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Error-[0-9]*:../../devel/p5-Error
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mail/DKIM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
