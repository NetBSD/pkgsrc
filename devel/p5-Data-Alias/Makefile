# $NetBSD: Makefile,v 1.16 2015/08/26 11:12:15 wiz Exp $

DISTNAME=	Data-Alias-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Alias/
COMMENT=	Comprehensive set of aliasing operations
LICENSE=	${PERL5_LICENSE}

# see https://rt.cpan.org/Public/Bug/Display.html?id=98758
# see https://rt.cpan.org/Public/Bug/Display.html?id=100944
BROKEN=		1.18 does not build with perl-5.22.0

PERL5_PACKLIST=	auto/Data/Alias/.packlist

USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
