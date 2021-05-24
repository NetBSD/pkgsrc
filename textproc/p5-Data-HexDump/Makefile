# $NetBSD: Makefile,v 1.20 2021/05/24 19:54:28 wiz Exp $

DISTNAME=	Data-HexDump-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
