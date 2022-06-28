# $NetBSD: Makefile,v 1.18 2022/06/28 11:32:05 wiz Exp $

DISTNAME=	Clone-Fast-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}
# as of 2015-01-30, above doesn't make it
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JJ/JJORE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone-Fast
COMMENT=	Natively copying Perl data structures
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Clone/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
