# $NetBSD: Makefile,v 1.3 2016/06/08 19:23:41 wiz Exp $

DISTNAME=	Test-Spelling-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sartak/Test-Spelling/
COMMENT=	Test::Spelling - check for spelling errors in POD files
LICENSE=        ${PERL5_LICENSE}

DEPENDS+=	p5-Module-Install-GithubMeta-[0-9]*:../../devel/p5-Module-Install-GithubMeta
DEPENDS+=	p5-Module-Manifest-Skip-[0-9]*:../../devel/p5-Module-Manifest-Skip
DEPENDS+=	p5-Pod-Spell-[0-9]*:../../textproc/p5-Pod-Spell

USE_LANGUAGES=  # empty
PERL5_PACKLIST= auto/Test/Spelling/.packlist

# url2pkg-marker (please do not remove this line.)
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
