# $NetBSD: Makefile,v 1.1.1.1 2005/01/25 15:59:14 cube Exp $

DISTNAME=	Class-Factory-Util-1.6
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Factory-Util/
COMMENT=	Perl module to help factory classes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Factory/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
