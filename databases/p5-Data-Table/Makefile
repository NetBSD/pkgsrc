# $NetBSD: Makefile,v 1.33 2023/07/06 09:38:26 wiz Exp $

DISTNAME=	Data-Table-1.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Table
COMMENT=	Data type related to database tables, spreadsheets, etc
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
