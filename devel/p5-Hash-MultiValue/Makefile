# $NetBSD: Makefile,v 1.26 2026/07/16 19:02:35 wiz Exp $
#

DISTNAME=		Hash-MultiValue-0.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Hash-MultiValue
COMMENT=		Perl5 module to store multiple values per key
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hash/MultiValue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
