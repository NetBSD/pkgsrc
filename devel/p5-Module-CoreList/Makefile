# $NetBSD: Makefile,v 1.6 2005/05/19 23:28:15 seb Exp $
#

DISTNAME=	Module-CoreList-2.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mcl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-CoreList/
COMMENT=	Perl 5 module inventorying modules shipped with core Perl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Module/CoreList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
