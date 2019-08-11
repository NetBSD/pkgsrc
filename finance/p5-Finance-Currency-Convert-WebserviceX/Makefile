# $NetBSD: Makefile,v 1.17 2019/08/11 13:21:00 wiz Exp $

DISTNAME=	Finance-Currency-Convert-WebserviceX-0.07001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Finance::Currency::Convert::WebserviceX
COMMENT=	Lightweight currency conversion using WebserviceX.NET
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Finance/Currency/Convert/WebserviceX/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
