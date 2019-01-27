# $NetBSD: Makefile,v 1.18 2019/01/27 13:26:38 wen Exp $

DISTNAME=	Unicode-Normalize-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~khw/Unicode-Normalize/
COMMENT=	Unicode Normalization Froms
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Unicode/Normalize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
