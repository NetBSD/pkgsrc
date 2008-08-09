# $NetBSD: Makefile,v 1.3 2008/08/09 01:19:34 obache Exp $
#

DISTNAME=	PPI-1.203
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPI/
COMMENT=	Perl 5 module to parse, analyze and manipulate Perl (without perl)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Clone>=0.25:../../devel/p5-Clone
DEPENDS+=	p5-IO-String>=1.07:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils>=0.16:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Params-Util>=0.21:../../devel/p5-Params-Util

BUILD_DEPENDS+=	p5-Task-Weaken>=0.06:../../devel/p5-Task-Weaken
BUILD_DEPENDS+=	p5-Test-Object>=0.07:../../devel/p5-Test-Object

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PPI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
