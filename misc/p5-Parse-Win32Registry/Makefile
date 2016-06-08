# $NetBSD: Makefile,v 1.5 2016/06/08 19:24:07 wiz Exp $

DISTNAME=		Parse-Win32Registry-1.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Parse Windows Registry Files
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Parse/Win32Registry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
