# $NetBSD: Makefile,v 1.2 2011/10/17 21:03:29 joerg Exp $

DISTNAME=		Module-Runtime-0.010
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-Runtime/
COMMENT=		Deal with runtime handling of Perl modules
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Params-Classify-[0-9]*:../../devel/p5-Params-Classify

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Runtime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
