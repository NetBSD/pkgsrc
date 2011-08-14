# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:38 obache Exp $
#

DISTNAME=	Term-Prompt-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Prompt/
COMMENT=	Perl extension for prompting a user for information

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-Tabs+Wrap>=1.0:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-Term-ReadKey>=1.0:../../devel/p5-Term-ReadKey

PERL5_PACKLIST=		auto/Term/Prompt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
