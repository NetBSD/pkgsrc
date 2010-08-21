# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:34 seb Exp $
#

DISTNAME=	Devel-EvalContext-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-EvalContext/
COMMENT=	Perl 5 module to save lexicals and hints between calls to eval

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Devel/EvalContext/.packlist

DEPENDS+=	p5-Data-Alias>=1.01:../../devel/p5-Data-Alias
DEPENDS+=	p5-PadWalker>=1.0:../../devel/p5-PadWalker
DEPENDS+=	p5-YAML>=0.62:../../textproc/p5-YAML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
