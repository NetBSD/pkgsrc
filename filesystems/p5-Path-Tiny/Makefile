# $NetBSD: Makefile,v 1.23 2017/06/05 14:23:57 ryoon Exp $

DISTNAME=	Path-Tiny-0.104
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Path-Tiny/
COMMENT=	Perl5 file path utility
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Path/Tiny/.packlist

#DEPENDS+=	{perl>=5.18.0,p5-PathTools>=3.40}:../../devel/p5-PathTools

BUILD_DEPENDS+=	p5-Devel-Hide-[0-9]*:../../devel/p5-Devel-Hide
BUILD_DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
