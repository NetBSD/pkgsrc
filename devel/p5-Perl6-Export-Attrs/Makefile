# $NetBSD: Makefile,v 1.20 2019/06/30 20:15:36 nia Exp $

DISTNAME=	Perl6-Export-Attrs-0.000006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Perl6-Export-Attrs
COMMENT=	Perl 5 module implementing Perl 6 symbol export mechanism

#DEPENDS+=	{perl>=5.9.0,p5-version-[0-9]*}:../../devel/p5-version
DEPENDS+=	p5-PadWalker>=0:../../devel/p5-PadWalker

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl6/Export/Attrs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
