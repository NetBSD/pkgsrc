# $NetBSD: Makefile,v 1.18 2020/09/08 13:16:44 wiz Exp $

DISTNAME=	Data-HexDump-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FT/FTASSIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::HexDump
COMMENT=	Hexadecial Dumper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/HexDump/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
