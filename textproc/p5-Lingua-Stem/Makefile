# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:05 obache Exp $

DISTNAME=	Lingua-Stem-0.84
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Stem/
COMMENT=	Stemming of words
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lingua-PT-Stemmer-[0-9]*:../../textproc/p5-Lingua-PT-Stemmer
DEPENDS+=	p5-Lingua-Stem-Fr>=0.02:../../textproc/p5-Lingua-Stem-Fr
DEPENDS+=	p5-Lingua-Stem-It-[0-9]*:../../textproc/p5-Lingua-Stem-It
DEPENDS+=	p5-Lingua-Stem-Ru-[0-9]*:../../textproc/p5-Lingua-Stem-Ru
DEPENDS+=	p5-Lingua-Stem-Snowball-Da>=1.01:../../textproc/p5-Lingua-Stem-Snowball-Da
DEPENDS+=	p5-Snowball-Norwegian>=1.0:../../textproc/p5-Snowball-Norwegian
DEPENDS+=	p5-Snowball-Swedish>=1.01:../../textproc/p5-Snowball-Swedish
DEPENDS+=	p5-Text-German-[0-9]*:../../textproc/p5-Text-German

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Lingua/Stem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
