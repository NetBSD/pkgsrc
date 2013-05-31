# $NetBSD: Makefile,v 1.25 2013/05/31 12:42:14 wiz Exp $
#

DISTNAME=	Text-Balanced-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5tba
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Balanced/
COMMENT=	Extract delimited text sequences from strings
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
