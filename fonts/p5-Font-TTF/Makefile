# $NetBSD: Makefile,v 1.38 2024/11/16 12:05:39 wiz Exp $
#

DISTNAME=	Font-TTF-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MHOSKEN/Font-TTF-1.05
COMMENT=	Perl module for TrueType font hacking
LICENSE=	artistic-2.0

DEPENDS+=		p5-IO-String>=0:../../devel/p5-IO-String

PERL5_PACKLIST=		auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
