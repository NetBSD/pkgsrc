# $NetBSD: Makefile,v 1.5 2010/08/31 05:45:14 sno Exp $
#

DISTNAME=	Test-Most-0.22
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Most
COMMENT=	Most commonly needed test functions and features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Exception>0.29:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Differences>0.500:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Deep>0.106:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Harness>3.07:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-Warn>0.11:../../devel/p5-Test-Warn

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Test-Most
PKG_SUPPORTED_OPTIONS+=	data-dumper-names
PKG_SUGGESTED_OPTIONS+=	# empty

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdata-dumper-names)
DEPENDS+=	p5-Data-Dumper-Names>=0.03:../../devel/p5-Data-Dumper-Names
.endif

PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Most/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
