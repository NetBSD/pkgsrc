# $NetBSD: Makefile,v 1.16 2022/06/28 11:36:25 wiz Exp $
#

DISTNAME=		String-Flogger-1.101245
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-Flogger
COMMENT=		Perl 5 module for string munging for loggers
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

#BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/String/Flogger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
