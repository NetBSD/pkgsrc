# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:12 obache Exp $
#

DISTNAME=	Text-DoubleMetaphone-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-DoubleMetaphone/
COMMENT=	Double Metaphone "sounds like" algorithm

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Text/DoubleMetaphone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
