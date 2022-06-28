# $NetBSD: Makefile,v 1.35 2022/06/28 11:34:29 wiz Exp $

DISTNAME=		Mail-ListDetector-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Mail-ListDetector
COMMENT=		Perl5 module to detect messages from a mailing lists
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Email-Abstract-[0-9]*:../../mail/p5-Email-Abstract
DEPENDS+=		p5-Email-Valid>=0.12:../../mail/p5-Email-Valid
DEPENDS+=		p5-URI>=1.10:../../www/p5-URI

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Mail/ListDetector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
