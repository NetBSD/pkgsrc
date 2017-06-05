# $NetBSD: Makefile,v 1.28 2017/06/05 14:24:13 ryoon Exp $

DISTNAME=	Business-ISBN-Data-20140910.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=	Data for the p5-Business-ISBN package
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Business/ISBN/Data/.packlist
REPLACE_PERL+=	make_data.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
