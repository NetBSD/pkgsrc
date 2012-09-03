# $NetBSD: Makefile,v 1.6 2012/09/03 11:16:22 sno Exp $

DISTNAME=	Finance-Currency-Convert-WebserviceX-0.07001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Finance::Currency::Convert::WebserviceX
COMMENT=	Lightweight currency conversion using WebserviceX.NET
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Finance/Currency/Convert/WebserviceX/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
