# $NetBSD: Makefile,v 1.3 2009/09/22 17:57:39 sno Exp $

DISTNAME=	Test-Class-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Class
COMMENT=	Easily create test classes in an xUnit/JUnit style
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{p5-Attribute-Handlers>=0.77,perl>=5.10.0}:../../devel/p5-Attribute-Handlers
DEPENDS+=	p5-Class-ISA>=0.32:../../devel/p5-Class-ISA
DEPENDS+=	p5-Devel-Symdump>=2.03:../../devel/p5-Devel-Symdump
DEPENDS+=	{perl>=5.10.0,p5-Storable>=2.04}:../../devel/p5-Storable
DEPENDS+=	p5-Test-Exception>=0.25:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Simple>=0.78:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
