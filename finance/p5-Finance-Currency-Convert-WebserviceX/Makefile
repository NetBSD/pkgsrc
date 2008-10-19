# $NetBSD: Makefile,v 1.2 2008/10/19 19:18:09 he Exp $

DISTNAME=	Finance-Currency-Convert-WebserviceX-0.07000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Finance::Currency::Convert::WebserviceX
COMMENT=	Lightweight currency conversion using WebserviceX.NET

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Finance/Currency/Convert/WebserviceX/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
