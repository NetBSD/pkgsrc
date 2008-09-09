# $NetBSD: Makefile,v 1.1.1.1 2008/09/09 00:04:32 seb Exp $
#

DISTNAME=	Test-WWW-Selenium-1.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Selenium/
COMMENT=	Perl 5 module to test applications using Selenium Remote Control

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/WWW/Selenium/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Mock-LWP-[0-9]*:../../devel/p5-Test-Mock-LWP
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
