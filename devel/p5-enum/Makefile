# $NetBSD: Makefile,v 1.20 2019/08/11 13:20:46 wiz Exp $

DISTNAME=	enum-1.11
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=enum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/enum
COMMENT=	Enumerations for Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/enum/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
