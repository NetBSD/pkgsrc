# $NetBSD: Makefile,v 1.19 2016/06/08 19:23:39 wiz Exp $

DISTNAME=	Test-MockObject-1.20150527
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-MockObject/
COMMENT=	Tests remote URLs or local web files

#DEPENDS+=	{perl>=5.004,p5-CGI-[0-9]*}:../../www/p5-CGI
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Test-Exception>=0.31:../../devel/p5-Test-Exception
#DEPENDS+=	{perl>=5.14.0,p5-Test-Simple>=0.98}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Warn>=0.23:../../devel/p5-Test-Warn
DEPENDS+=	p5-UNIVERSAL-can>=1.20110617:../../devel/p5-UNIVERSAL-can
DEPENDS+=	p5-UNIVERSAL-isa>=1.20110614:../../devel/p5-UNIVERSAL-isa

BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

INSTALL_TARGET=	pure_install

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/MockObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
