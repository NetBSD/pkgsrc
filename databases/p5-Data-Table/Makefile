# $NetBSD: Makefile,v 1.18 2015/05/01 00:57:50 wen Exp $

DISTNAME=	Data-Table-1.72
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Table/
COMMENT=	Data type related to database tables, spreadsheets, etc
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
