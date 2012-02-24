# $NetBSD: Makefile,v 1.1.1.1 2012/02/24 09:40:52 fhajny Exp $
#

DISTNAME=	Lingua-Identify-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Identify/
COMMENT=	Language identification
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Factory-Util>=1.6:../../devel/p5-Class-Factory-Util
DEPENDS+=	p5-Text-Affixes>=0.07:../../textproc/p5-Text-Affixes
DEPENDS+=	p5-Text-Ngram>=0.13:../../textproc/p5-Text-Ngram

PERL5_PACKLIST=	auto/Lingua/Identify/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
