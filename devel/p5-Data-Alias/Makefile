# $NetBSD: Makefile,v 1.15 2015/06/12 10:49:04 wiz Exp $

DISTNAME=	Data-Alias-1.18
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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
