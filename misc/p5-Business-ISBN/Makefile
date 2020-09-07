# $NetBSD: Makefile,v 1.47 2020/09/07 12:01:25 wiz Exp $

DISTNAME=	Business-ISBN-3.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Business-ISBN
COMMENT=	Perl5 module to work with International Standard Book Numbers (ISBNs)
LICENSE=	artistic-2.0

DEPENDS+=	p5-Business-ISBN-Data>=20191107:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
