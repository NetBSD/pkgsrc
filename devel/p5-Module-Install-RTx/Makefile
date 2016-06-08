# $NetBSD: Makefile,v 1.17 2016/06/08 19:23:11 wiz Exp $

DISTNAME=	Module-Install-RTx-0.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-RTx/
COMMENT=	Perl5 module for building and installing RT extensions
LICENSE=	mit

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PERL5_PACKLIST=		auto/Module/Install/RTx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
