# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:40 obache Exp $

DISTNAME=	Test-Class-0.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Class
COMMENT=	Easily create test classes in an xUnit/JUnit style
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{p5-Attribute-Handlers>=0.77,perl>=5.10.0}:../../devel/p5-Attribute-Handlers
DEPENDS+=	p5-MRO-Compat>=0.11:../../devel/p5-MRO-Compat
DEPENDS+=	{perl>=5.10.0,p5-Storable>=2.04}:../../devel/p5-Storable
DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.78}:../../devel/p5-Test-Simple

BUILD_DEPENDS+=	p5-Test-Exception>=0.25:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
