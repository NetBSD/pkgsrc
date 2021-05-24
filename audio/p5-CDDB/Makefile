# $NetBSD: Makefile,v 1.29 2021/05/24 19:49:06 wiz Exp $

DISTNAME=	CDDB-1.222
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
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
