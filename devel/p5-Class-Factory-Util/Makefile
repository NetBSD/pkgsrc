# $NetBSD: Makefile,v 1.10 2011/08/10 04:11:32 adam Exp $

DISTNAME=	Class-Factory-Util-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Factory-Util/
COMMENT=	Perl module to help factory classes
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/Factory/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
