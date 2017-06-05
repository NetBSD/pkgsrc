# $NetBSD: Makefile,v 1.35 2017/06/05 14:24:48 ryoon Exp $

DISTNAME=		Text-CSV-Hash-0.18
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/Text-CSV-Hash/
EXTRACT_SUFX=		.tbz

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.mono.org/abs/tools/Text-CSV-Hash/
COMMENT=		Perl5 module for hash based CSV usage

PERL5_PACKLIST=		auto/Text/CSV/Hash/.packlist

# The provided test.pl is not a unit test.
TEST_TARGET=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
