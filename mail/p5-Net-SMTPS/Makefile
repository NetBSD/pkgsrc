# $NetBSD: Makefile,v 1.1 2024/01/10 16:20:32 schmonz Exp $

DISTNAME=		Net-SMTPS-0.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Net::SMTPS
COMMENT=		SSL/STARTTLS support for Net::SMTP
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Authen-SASL>=2:../../security/p5-Authen-SASL
DEPENDS+=		p5-IO-Socket-SSL>=1:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-Net>=2:../../net/p5-Net

PERL5_PACKLIST=		auto/Net/SMTPS/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
