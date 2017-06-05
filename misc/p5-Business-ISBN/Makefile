# $NetBSD: Makefile,v 1.42 2017/06/05 14:24:13 ryoon Exp $

DISTNAME=	Business-ISBN-3.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Business-ISBN/
COMMENT=	Perl5 module to work with International Standard Book Numbers (ISBNs)
LICENSE=	artistic-2.0

DEPENDS+=	p5-Business-ISBN-Data>=20140910.002:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
