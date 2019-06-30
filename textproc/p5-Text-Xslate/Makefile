# $NetBSD: Makefile,v 1.36 2019/06/30 20:17:05 nia Exp $

DISTNAME=	Text-Xslate-v3.5.6
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKAJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Xslate
COMMENT=	Scalable template engine for Perl5
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Data-MessagePack>=0.38:../../devel/p5-Data-MessagePack
#DEPENDS+=	{perl>=5.10.1,p5-parent>=0.221}:../../devel/p5-parent
DEPENDS+=	p5-Mouse>=2.5.0:../../devel/p5-Mouse
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
# only for regress test
DEPENDS+=	p5-File-Copy-Recursive>=0:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-Test-LeakTrace>=0:../../devel/p5-Test-LeakTrace
DEPENDS+=	p5-Module-Build-XSUtil-[0-9]*:../../devel/p5-Module-Build-XSUtil

PERL5_PACKLIST=	auto/Text/Xslate/.packlist
PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=	c

PERL5_MODULE_TYPE=	Module::Build

# XXX Kick can down the road and hope the developer fixes this issue.
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
