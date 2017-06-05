# $NetBSD: Makefile,v 1.2 2017/06/05 14:22:46 ryoon Exp $

DISTNAME=		Config-INI-Reader-Ordered-0.020
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Config-INI-Reader-Ordered/
COMMENT=		Perl .ini-file parser that returns sections in order
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Config-INI-[0-9]*:../../devel/p5-Config-INI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/INI/Reader/Ordered/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
