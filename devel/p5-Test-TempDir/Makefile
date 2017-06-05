# $NetBSD: Makefile,v 1.18 2017/06/05 14:23:47 ryoon Exp $

DISTNAME=	Test-TempDir-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-TempDir/
COMMENT=	Temporary files support for testing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-NFSLock>=0:../../devel/p5-File-NFSLock
#DEPENDS+=	{p5-File-Path>=2.04,perl>=5.10}:../../devel/p5-File-Path
DEPENDS+=	p5-Moose>=0.87:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-Path-Class>=0:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/TempDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
