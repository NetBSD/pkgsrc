# $NetBSD: Makefile,v 1.24 2015/06/12 10:50:34 wiz Exp $

DISTNAME=	Business-ISBN-Data-20140910.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=	Data for the p5-Business-ISBN package
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Business/ISBN/Data/.packlist
REPLACE_PERL+=	make_data.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
