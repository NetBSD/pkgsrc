# $NetBSD: Makefile,v 1.24 2022/06/28 11:33:38 wiz Exp $

DISTNAME=	enum-1.12
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
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
