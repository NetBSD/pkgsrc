# $NetBSD: Makefile,v 1.21 2017/09/16 13:20:11 tnn Exp $

DISTNAME=	Data-Alias-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Alias/
COMMENT=	Comprehensive set of aliasing operations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/Alias/.packlist

USE_LANGUAGES=	c

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

BROKEN=		Not compatible with the current version of Perl.
BROKEN+=	See: https://rt.cpan.org/Public/Bug/Display.html?id=114544

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
