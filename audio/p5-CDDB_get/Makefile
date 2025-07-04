# $NetBSD: Makefile,v 1.33 2025/07/04 08:44:45 wiz Exp $

DISTNAME=	CDDB_get-2.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FO/FONKIE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CDDB_get
COMMENT=	Perl interface to query for CDDB information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CDDB_get/.packlist

USE_LANGUAGES=		# empty
REPLACE_PERL+=		cddb.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
