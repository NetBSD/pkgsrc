# $NetBSD: Makefile,v 1.8 2006/06/05 18:33:55 minskim Exp $
#

DISTNAME=       Text-Reform-1.11
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5trf
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/search?module=Text::Reform
COMMENT=	Manual text wrapping and reformatting

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/Reform/.packlist

REPLACE_PERL+=	demo*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
