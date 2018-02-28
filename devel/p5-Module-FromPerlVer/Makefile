# $NetBSD: Makefile,v 1.1 2018/02/28 08:36:12 wiz Exp $

DISTNAME=		Module-FromPerlVer-0.0.1
PKGNAME=        	p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-FromPerlVer/
COMMENT=		Install modules compatible with the running perl
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-FindBin-libs-[0-9]*:../../devel/p5-FindBin-libs
DEPENDS+=		p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive

PERL5_PACKLIST=		auto/Module/FromPerlVer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
