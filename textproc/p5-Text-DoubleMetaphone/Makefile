# $NetBSD: Makefile,v 1.6 2013/05/31 12:42:15 wiz Exp $
#

DISTNAME=	Text-DoubleMetaphone-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-DoubleMetaphone/
COMMENT=	Double Metaphone "sounds like" algorithm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Text/DoubleMetaphone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
