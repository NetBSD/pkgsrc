# $NetBSD: Makefile,v 1.51 2023/07/06 09:40:58 wiz Exp $

DISTNAME=	Business-ISBN-3.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
