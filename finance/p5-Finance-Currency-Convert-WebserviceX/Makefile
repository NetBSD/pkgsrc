# $NetBSD: Makefile,v 1.12 2016/06/08 19:23:51 wiz Exp $

DISTNAME=	Finance-Currency-Convert-WebserviceX-0.07001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Finance::Currency::Convert::WebserviceX
COMMENT=	Lightweight currency conversion using WebserviceX.NET
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Finance/Currency/Convert/WebserviceX/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
