# $NetBSD: Makefile,v 1.13 2013/05/31 12:40:31 wiz Exp $
#

DISTNAME=	Module-Starter-1.58
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Starter/
COMMENT=	Perl 5 module acting as a simple starter kit for any module
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Module/Starter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
