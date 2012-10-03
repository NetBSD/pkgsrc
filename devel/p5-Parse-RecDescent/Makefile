# $NetBSD: Makefile,v 1.27 2012/10/03 21:55:28 wiz Exp $
#

DISTNAME=	Parse-RecDescent-1.965001
PKGNAME=	p5-${DISTNAME:S/965001/965.1/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-RecDescent/
COMMENT=	Perl5 module to generate recursive-descent parsers
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/RecDescent/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
