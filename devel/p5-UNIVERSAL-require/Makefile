# $NetBSD: Makefile,v 1.26 2023/07/06 09:40:25 wiz Exp $

DISTNAME=	UNIVERSAL-require-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/UNIVERSAL-require
COMMENT=	Perl module to require() from a variable
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/UNIVERSAL/require/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
