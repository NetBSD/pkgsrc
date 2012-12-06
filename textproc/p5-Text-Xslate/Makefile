# $NetBSD: Makefile,v 1.6 2012/12/06 12:59:09 wen Exp $
#

DISTNAME=	Text-Xslate-1.6001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Xslate/
COMMENT=	Scalable template engine for Perl5
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Any-Moose>=0.13:../../devel/p5-Any-Moose
DEPENDS+=	p5-Data-MessagePack>=0.38:../../devel/p5-Data-MessagePack
DEPENDS+=	p5-parent>=0.21:../../devel/p5-parent
DEPENDS+=	p5-Mouse>=0.61:../../devel/p5-Mouse
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
# only for regress test
DEPENDS+=	p5-File-Copy-Recursive>=0:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-Test-LeakTrace>=0:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=	auto/Text/Xslate/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
