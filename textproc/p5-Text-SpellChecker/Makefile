# $NetBSD: Makefile,v 1.6 2011/08/14 15:14:14 obache Exp $
#

DISTNAME=	Text-SpellChecker-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5tsc
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-SpellChecker/
COMMENT=	Perl5 OO interface for spell-checking a block of text
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Aspell>=0.04:../../textproc/p5-Text-Aspell
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/SpellChecker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
