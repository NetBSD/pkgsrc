# $NetBSD: Makefile,v 1.1.1.1 2009/02/14 00:12:30 abs Exp $
#

DISTNAME=	Test-Most-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Most
COMMENT=	Most commonly needed test functions and features

DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-Test-Simple>=0.82:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Exception>0:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Differences>0:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Deep>0:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Harness>3.07:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-Warn>0.10:../../devel/p5-Test-Warn

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Most/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
