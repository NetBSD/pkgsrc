# $NetBSD: Makefile,v 1.1 2024/01/10 16:15:21 schmonz Exp $

DISTNAME=		Net-IMAP-Simple-1.2212
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JE/JETTERO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/Net-IMAP-Simple
COMMENT=		Perl extension for simple IMAP account handling
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Parse-RecDescent>=0:../../devel/p5-Parse-RecDescent

PERL5_PACKLIST=		auto/Net/IMAP/Simple/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
