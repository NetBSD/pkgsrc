# $NetBSD: Makefile,v 1.39 2016/06/08 19:22:36 wiz Exp $

DISTNAME=	BSD-Resource-1.2910
PKGNAME=	p5-${DISTNAME:C/([0-9][0-9])([0-9][0-9])/\1.\2/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BSD-Resource/
COMMENT=	Perl interface to BSD process resources library
LICENSE=	artistic-2.0 OR gnu-lgpl-v2

UNLIMIT_RESOURCES+=	stacksize

PERL5_PACKLIST=		auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
