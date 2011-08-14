# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:34 obache Exp $
#

DISTNAME=	Scalar-Defer-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Scalar-Defer/
COMMENT=	Perl 5 module providing lazy evaluation
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Scalar/Defer/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Class-InsideOut-[0-9]*:../../devel/p5-Class-InsideOut
DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
