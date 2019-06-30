# $NetBSD: Makefile,v 1.24 2019/06/30 20:15:53 nia Exp $

DISTNAME=	Test-MockObject-1.20180705
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-MockObject
COMMENT=	Perl extension for emulating troublesome interfaces
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-UNIVERSAL-can>=1.20110617:../../devel/p5-UNIVERSAL-can
DEPENDS+=	p5-UNIVERSAL-isa>=1.20110614:../../devel/p5-UNIVERSAL-isa

# XXX for test
BUILD_DEPENDS+=	p5-CGI>=4.15:../../www/p5-CGI
BUILD_DEPENDS+=	p5-Test-Exception>=0.31:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn>=0.23:../../devel/p5-Test-Warn

INSTALL_TARGET=	pure_install

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/MockObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
