# $NetBSD: Makefile,v 1.14 2016/06/08 19:22:22 wiz Exp $

DISTNAME=	Unicode-Normalize-1.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sadahiro/Unicode-Normalize
COMMENT=	Unicode Normalization Froms

LICENSE=	${PERL5_LICENSE}
USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Unicode/Normalize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
