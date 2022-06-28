# $NetBSD: Makefile,v 1.32 2022/06/28 11:33:53 wiz Exp $

DISTNAME=		Font-AFM-1.20
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		fonts perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Font-AFM
COMMENT=		Perl5 modules for parsing PostScript font metrics files

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Font/AFM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
