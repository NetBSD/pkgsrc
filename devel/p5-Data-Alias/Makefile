# $NetBSD: Makefile,v 1.29 2021/07/06 08:16:20 wen Exp $

DISTNAME=	Data-Alias-1.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Alias
COMMENT=	Comprehensive set of aliasing operations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Alias/.packlist

USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
