# $NetBSD: Makefile,v 1.2 2010/08/21 16:33:38 seb Exp $
#

DISTNAME=	Devel-ebug-0.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-ebug/
COMMENT=	Simple, extensible Perl 5 debugger

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-PadWalker-[0-9]*:../../devel/p5-PadWalker
DEPENDS+=	p5-Proc-Background-[0-9]*:../../devel/p5-Proc-Background
DEPENDS+=	p5-String-Koremutake-[0-9]*:../../textproc/p5-String-Koremutake
DEPENDS+=	p5-YAML-Syck>=0.85:../../textproc/p5-YAML-Syck

# for test target
BUILD_DEPENDS+=	p5-Test-Expect-[0-9]*:../../devel/p5-Test-Expect

PERL5_PACKLIST=	auto/Devel/ebug/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
