# $NetBSD: Makefile,v 1.44 2024/11/16 12:03:53 wiz Exp $

DISTNAME=	Clone-0.47
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone
COMMENT=	Perl module for recursively copying datatypes
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-B-COW-[0-9]*:../../devel/p5-B-COW

PERL5_PACKLIST=		auto/Clone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
