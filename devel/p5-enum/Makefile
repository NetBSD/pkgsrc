# $NetBSD: Makefile,v 1.1.1.1 2007/01/25 03:08:19 rillig Exp $
#

DISTNAME=	enum-1.016
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=enum/}

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~zenin/${DISTNAME}/enum.pm
COMMENT=	Enumerations for Perl

PERL5_PACKLIST=	auto/enum/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
