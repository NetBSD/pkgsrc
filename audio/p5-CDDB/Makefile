# $NetBSD: Makefile,v 1.30 2022/06/28 11:30:56 wiz Exp $

DISTNAME=	CDDB-1.222
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CDDB
COMMENT=	High-level interface to the Compact Disc Database
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	CDDB-[0-9]*
SUPERSEDES=	CDDB<=1.17nb1

PERL5_PACKLIST=		auto/CDDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
