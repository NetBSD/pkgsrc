# $NetBSD: Makefile,v 1.9 2019/07/01 21:35:45 nia Exp $

DISTNAME=	Test-Spelling-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SARTAK/Test-Spelling-0.20
COMMENT=	Test::Spelling - check for spelling errors in POD files
LICENSE=        ${PERL5_LICENSE}

DEPENDS+=	p5-Module-Install-GithubMeta-[0-9]*:../../devel/p5-Module-Install-GithubMeta
DEPENDS+=	p5-Module-Manifest-Skip-[0-9]*:../../devel/p5-Module-Manifest-Skip
DEPENDS+=	p5-Pod-Spell-[0-9]*:../../textproc/p5-Pod-Spell

# for make test:
BUILD_DEPENDS+= p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
BUILD_DEPENDS+= p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3

USE_LANGUAGES=  # empty
PERL5_PACKLIST= auto/Test/Spelling/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
