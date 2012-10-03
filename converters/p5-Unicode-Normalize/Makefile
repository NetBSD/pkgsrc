# $NetBSD: Makefile,v 1.4 2012/10/03 00:20:15 asau Exp $

DISTNAME=	Unicode-Normalize-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sadahiro/Unicode-Normalize
COMMENT=	Unicode Normalization Froms

LICENSE=	${PERL5_LICENSE}
USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Unicode/Normalize/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
