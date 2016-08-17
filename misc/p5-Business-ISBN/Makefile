# $NetBSD: Makefile,v 1.39 2016/08/17 13:49:40 wen Exp $

DISTNAME=	Business-ISBN-3.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Business-ISBN/
COMMENT=	Perl5 module to work with International Standard Book Numbers (ISBNs)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Business-ISBN-Data>=20140910.002:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
