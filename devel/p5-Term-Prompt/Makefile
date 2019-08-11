# $NetBSD: Makefile,v 1.20 2019/08/11 13:20:25 wiz Exp $
#

DISTNAME=	Term-Prompt-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-Prompt
COMMENT=	Perl extension for prompting a user for information

#DEPENDS+=	{perl>=5,p5-Text-Tabs+Wrap>=1.0}:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-Term-ReadKey>=1.0:../../devel/p5-Term-ReadKey

PERL5_PACKLIST=		auto/Term/Prompt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
