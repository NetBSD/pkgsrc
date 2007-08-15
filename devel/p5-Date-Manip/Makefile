# $NetBSD: Makefile,v 1.22 2007/08/15 06:19:34 obache Exp $
#

DISTNAME=	DateManip-5.44
PKGNAME=	${DISTNAME:S/DateManip/p5-Date-Manip/}
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateManip/
COMMENT=	Perl5 module for date calculations

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
