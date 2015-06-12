# $NetBSD: Makefile,v 1.59 2015/06/12 10:49:26 wiz Exp $
#

DISTNAME=	Module-CoreList-5.20150420
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-CoreList
COMMENT=	Perl 5 module inventorying modules shipped with core Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/CoreList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
