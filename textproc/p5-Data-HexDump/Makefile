# $NetBSD: Makefile,v 1.6 2012/10/03 21:57:51 wiz Exp $
#

DISTNAME=	Data-HexDump-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/F/FT/FTASSIN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/F/FT/FTASSIN/
COMMENT=	Hexadecial Dumper
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Data/HexDump/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
