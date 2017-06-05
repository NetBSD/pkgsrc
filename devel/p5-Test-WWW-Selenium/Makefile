# $NetBSD: Makefile,v 1.18 2017/06/05 14:23:47 ryoon Exp $
#

DISTNAME=	Test-WWW-Selenium-1.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Selenium/
COMMENT=	Perl 5 module to test applications using Selenium Remote Control
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/WWW/Selenium/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
# contains URI::Escape 3.30
DEPENDS+=	p5-URI>=1.54:../../www/p5-URI

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Mock-LWP-[0-9]*:../../devel/p5-Test-Mock-LWP
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
