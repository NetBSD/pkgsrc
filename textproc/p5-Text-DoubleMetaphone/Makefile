# $NetBSD: Makefile,v 1.10 2015/09/03 02:58:10 dsainty Exp $
#

DISTNAME=	Text-DoubleMetaphone-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-DoubleMetaphone/
COMMENT=	Double Metaphone "sounds like" algorithm

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Text/DoubleMetaphone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
