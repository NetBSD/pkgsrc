# $NetBSD: Makefile,v 1.21 2023/07/06 09:39:33 wiz Exp $
#

DISTNAME=	Module-Install-ReadmeFromPod-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Install-ReadmeFromPod
COMMENT=	Module::Install extension to automatically convert POD to a README
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.05:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Module-Install>=0.85:../../devel/p5-Module-Install

# for make test
TOOL_DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
TOOL_DEPENDS+=	p5-Test-InDistDir-[0-9]*:../../devel/p5-Test-InDistDir
TOOL_DEPENDS+=	p5-Pod-Markdown-[0-9]*:../../textproc/p5-Pod-Markdown

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Install/ReadmeFromPod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
