# $NetBSD: Makefile,v 1.6 2021/05/24 19:51:23 wiz Exp $

DISTNAME=	Path-Iter-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DM/DMUEY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-Iter
COMMENT=	Perl module for simple efficient path iteration
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Path/Iter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
