# $NetBSD: Makefile,v 1.17 2011/08/14 13:25:26 obache Exp $
#

DISTNAME=		Mail-DKIM-0.38
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5mdk
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Mail-DKIM/
COMMENT=		Perl5 module for DKIM-based mail-signing and -verifying
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Crypt-OpenSSL-RSA>=0.24:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=		p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
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
