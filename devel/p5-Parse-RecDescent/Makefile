# $NetBSD: Makefile,v 1.15 2008/02/07 21:28:29 heinz Exp $
#

DISTNAME=	Parse-RecDescent-1.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-RecDescent/
COMMENT=	Perl5 module to generate recursive-descent parsers

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/RecDescent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
