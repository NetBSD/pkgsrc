# $NetBSD: Makefile,v 1.18 2023/07/06 09:41:46 wiz Exp $
#

DISTNAME=		String-Formatter-1.235
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-Formatter
COMMENT=		Perl 5 module to build sprintf-like functions of your own
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=		auto/String/Formatter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
