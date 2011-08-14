# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:27 obache Exp $
#

DISTNAME=	Package-Generator-0.103
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Package-Generator/
COMMENT=	Perl 5 module to generate new packages
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Package/Generator/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
