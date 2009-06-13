# $NetBSD: Makefile,v 1.2 2009/06/13 06:46:47 rillig Exp $

DISTNAME=	Test-TempDir-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-TempDir/
COMMENT=	Temporary files support for testing

DEPENDS+=	p5-File-NFSLock>=0:../../devel/p5-File-NFSLock
DEPENDS+=	{p5-File-Path>=2.04,perl>=5.10}:../../devel/p5-File-Path
DEPENDS+=	p5-Moose>=0.50:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-Path-Class>=0:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/TempDir/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
