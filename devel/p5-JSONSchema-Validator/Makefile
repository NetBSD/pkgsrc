# $NetBSD: Makefile,v 1.4 2022/06/28 11:32:38 wiz Exp $

DISTNAME=	JSONSchema-Validator-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LO/LOGIONIZ/}


MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/JSONSchema-Validator
COMMENT=	Perl module to validate JSONSchema and openapi
LICENSE=	mit

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-YAML-PP-[0-9]*:../../textproc/p5-YAML-PP

PERL5_PACKLIST=		auto/JSONSchema/Validator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
