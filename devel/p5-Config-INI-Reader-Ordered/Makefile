# $NetBSD: Makefile,v 1.11 2023/07/06 09:38:51 wiz Exp $

DISTNAME=		Config-INI-Reader-Ordered-0.022
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Config-INI-Reader-Ordered
COMMENT=		Perl .ini-file parser that returns sections in order
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Config-INI-[0-9]*:../../devel/p5-Config-INI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/INI/Reader/Ordered/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
