# $NetBSD: Makefile,v 1.15 2015/11/01 09:06:38 wiz Exp $

DISTNAME=	enum-1.11
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=enum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/enum/
COMMENT=	Enumerations for Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/enum/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
