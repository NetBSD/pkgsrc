# $NetBSD: Makefile,v 1.18 2022/06/28 11:36:25 wiz Exp $
#

DISTNAME=		String-Errf-0.008
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-Errf
COMMENT=		Perl 5 module providing a simple string formatter
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-String-Formatter>=0.102081:../../textproc/p5-String-Formatter
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
#DEPENDS+=	{perl>=5.10.1,p5-Time-Piece-[0-9]*}:../../time/p5-Time-Piece

BUILD_DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate
#BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
# autodie is in core since 5.10
# for make test
BUILD_DEPENDS+=		p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS

PERL5_PACKLIST=		auto/String/Errf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
