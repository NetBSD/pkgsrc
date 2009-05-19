# $NetBSD: Makefile,v 1.3 2009/05/19 07:31:05 abs Exp $
#

DISTNAME=	Test-Most-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Most
COMMENT=	Most commonly needed test functions and features
LICENSE=	artistic-2.0

DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-Test-Simple>=0.82:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Exception>0:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Differences>0:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Deep>0:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Harness>3.07:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-Warn>0.10:../../devel/p5-Test-Warn

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
