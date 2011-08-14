# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:45 obache Exp $
#

DISTNAME=	Test-WWW-Selenium-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Selenium/
COMMENT=	Perl 5 module to test applications using Selenium Remote Control
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

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
