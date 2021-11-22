# $NetBSD: Makefile,v 1.1 2021/11/22 11:36:10 wiz Exp $

DISTNAME=	JSONSchema-Validator-0.008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LO/LOGIONIZ/}


MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/JSONSchema-Validator
COMMENT=	Perl module to validate JSONSchema and openapi
LICENSE=	mit

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/JSONSchema/Validator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
