# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:39 ryoon Exp $
#

DISTNAME=	Data-HexDump-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/F/FT/FTASSIN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/F/FT/FTASSIN/
COMMENT=	Hexadecial Dumper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/HexDump/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
