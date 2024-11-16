# $NetBSD: Makefile,v 1.2 2024/11/16 12:05:33 wiz Exp $

DISTNAME=	match-simple-0.012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
#ASTER_SITES=	${MASTER_SITE_PERL_CPAN:=match/}
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TO/TOBYINK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/match::simple
COMMENT=	Clone of smartmatch operator
LICENSE=	gnu-gpl-v1 OR artistic

PERL5_PACKLIST=	auto/match/simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
