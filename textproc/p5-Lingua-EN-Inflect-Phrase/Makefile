# $NetBSD: Makefile,v 1.17 2019/06/30 20:16:50 nia Exp $

DISTNAME=	Lingua-EN-Inflect-Phrase-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-EN-Inflect-Phrase
COMMENT=	Inflect short English Phrases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lingua-EN-FindNumber-[0-9]*:../../textproc/p5-Lingua-EN-FindNumber
DEPENDS+=	p5-Lingua-EN-Inflect-[0-9]*:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-Lingua-EN-Inflect-Number-[0-9]*:../../textproc/p5-Lingua-EN-Inflect-Number
DEPENDS+=	p5-Lingua-EN-Number-IsOrdinal-[0-9]*:../../textproc/p5-Lingua-EN-Number-IsOrdinal
DEPENDS+=	p5-Lingua-EN-Tagger-[0-9]*:../../textproc/p5-Lingua-EN-Tagger

#BUILD_DEPENDS+=	{perl>=5.12.0,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Lingua/EN/Inflect/Phrase/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
