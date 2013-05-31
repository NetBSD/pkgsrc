# $NetBSD: Makefile,v 1.41 2013/05/31 12:40:30 wiz Exp $
#

DISTNAME=	Module-CoreList-2.73
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5mcl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-CoreList/
COMMENT=	Perl 5 module inventorying modules shipped with core Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/CoreList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
