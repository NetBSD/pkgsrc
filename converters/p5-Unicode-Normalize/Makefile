# $NetBSD: Makefile,v 1.7 2013/05/31 12:39:46 wiz Exp $

DISTNAME=	Unicode-Normalize-1.16
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

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
