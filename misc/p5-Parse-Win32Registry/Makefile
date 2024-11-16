# $NetBSD: Makefile,v 1.14 2024/11/16 12:06:06 wiz Exp $

DISTNAME=		Parse-Win32Registry-1.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Parse Windows Registry Files
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Parse/Win32Registry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
