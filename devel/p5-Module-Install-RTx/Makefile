# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:18 obache Exp $

DISTNAME=	Module-Install-RTx-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5mir
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-RTx/
COMMENT=	Perl5 module for building and installing RT extensions
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PERL5_PACKLIST=		auto/Module/Install/RTx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
