# $NetBSD: Makefile,v 1.2 2006/01/24 04:57:50 hiramatsu Exp $
#

DISTNAME=	Term-Prompt-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~persicom/Term-Prompt-1.03/
COMMENT=	Perl extension for prompting a user for information

DEPENDS+=	p5-Text-Tabs+Wrap>=1.0:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-Term-ReadKey>=1.0:../../devel/p5-Term-ReadKey

PERL5_PACKLIST=		auto/Term/Prompt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
