# $NetBSD: Makefile,v 1.12 2006/09/01 01:00:20 seb Exp $
#

DISTNAME=	Module-CoreList-2.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mcl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-CoreList/
COMMENT=	Perl 5 module inventorying modules shipped with core Perl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/CoreList/.packlist

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
