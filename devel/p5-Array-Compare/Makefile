# $NetBSD: Makefile,v 1.18 2011/08/07 07:57:48 adam Exp $

DISTNAME=	Array-Compare-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Array-Compare/
COMMENT=	Perl extension for comparing arrays
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Array/Compare/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
