# $NetBSD: Makefile,v 1.14 2014/02/22 09:33:20 wen Exp $
#

DISTNAME=	Text-Xslate-3.1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Xslate/
COMMENT=	Scalable template engine for Perl5
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Data-MessagePack>=0.38:../../devel/p5-Data-MessagePack
DEPENDS+=	{perl>=5.10.1,p5-parent>=0.221}:../../devel/p5-parent
DEPENDS+=	p5-Mouse>=1.08:../../devel/p5-Mouse
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
# only for regress test
DEPENDS+=	p5-File-Copy-Recursive>=0:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-Test-LeakTrace>=0:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=	auto/Text/Xslate/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
