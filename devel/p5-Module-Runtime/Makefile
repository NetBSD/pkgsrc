# $NetBSD: Makefile,v 1.1.1.1 2011/10/13 07:20:48 hiramatsu Exp $

DISTNAME=		Module-Runtime-0.010
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-Runtime/
COMMENT=		Deal with runtime handling of Perl modules
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Params-Classify:../../devel/p5-Params-Classify

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Runtime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
