# $NetBSD: Makefile,v 1.1.1.1 2008/11/18 05:29:18 he Exp $
#

DISTNAME=	Text-SpellChecker-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tsc
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-SpellChecker/
COMMENT=	Perl5 OO interface for spell-checking a block of text

DEPENDS+=	p5-Text-Aspell>=0.04:../../textproc/p5-Text-Aspell
DEPENDS+=	p5-MIME-Base64>=1:../../converters/p5-MIME-Base64

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/SpellChecker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
