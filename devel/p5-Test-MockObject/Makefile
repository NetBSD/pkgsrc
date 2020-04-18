# $NetBSD: Makefile,v 1.28 2020/04/18 11:20:16 mef Exp $

DISTNAME=	Test-MockObject-1.20200122
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-MockObject
COMMENT=	Perl extension for emulating troublesome interfaces
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-UNIVERSAL-can>=1.20110617:../../devel/p5-UNIVERSAL-can
DEPENDS+=	p5-UNIVERSAL-isa>=1.20110614:../../devel/p5-UNIVERSAL-isa

TEST_DEPENDS+=	p5-CGI>=4.15:../../www/p5-CGI
TEST_DEPENDS+=	p5-Test-Exception>=0.31:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Warn>=0.23:../../devel/p5-Test-Warn

INSTALL_TARGET=	pure_install

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/MockObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
