# $NetBSD: Makefile,v 1.2 2011/08/14 12:26:39 obache Exp $
#

DISTNAME=	Test-Approx-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Approx
COMMENT=	Perl module for testing approximate equality of values
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-LevenshteinXS>=0.03:../../textproc/p5-Text-LevenshteinXS

PERL5_PACKLIST=		auto/Test/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
