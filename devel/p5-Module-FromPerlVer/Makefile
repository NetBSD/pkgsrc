# $NetBSD: Makefile,v 1.2 2018/03/04 11:15:22 wiz Exp $

DISTNAME=		Module-FromPerlVer-0.000004
PKGNAME=        	p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-FromPerlVer/
COMMENT=		Install modules compatible with the running perl
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive

PERL5_PACKLIST=		auto/Module/FromPerlVer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
