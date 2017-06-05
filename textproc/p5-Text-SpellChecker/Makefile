# $NetBSD: Makefile,v 1.17 2017/06/05 14:24:52 ryoon Exp $
#

DISTNAME=	Text-SpellChecker-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-SpellChecker/
COMMENT=	Perl5 OO interface for spell-checking a block of text
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Aspell>=0.04:../../textproc/p5-Text-Aspell
#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Text/SpellChecker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
