# $NetBSD: Makefile,v 1.19 2021/04/27 16:21:13 wiz Exp $

DISTNAME=	Data-HexDump-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::HexDump
COMMENT=	Hexadecial Dumper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/HexDump/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
