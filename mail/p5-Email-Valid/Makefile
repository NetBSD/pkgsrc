# $NetBSD: Makefile,v 1.50 2024/01/28 11:46:48 wiz Exp $

DISTNAME=		Email-Valid-1.204
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Email-Valid
COMMENT=		Perl5 module for testing validity of an email address
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-Net-Domain-TLD-[0-9]*:../../net/p5-Net-Domain-TLD

PERL5_PACKLIST=		auto/Email/Valid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
