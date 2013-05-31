# $NetBSD: Makefile,v 1.17 2013/05/31 12:42:17 wiz Exp $
#

DISTNAME=	Text-Reform-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5trf
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/search?module=Text::Reform
COMMENT=	Manual text wrapping and reformatting
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/Reform/.packlist
PERL5_MODULE_TYPE=	Module::Build

REPLACE_PERL+=	demo*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
