# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:25 wiz Exp $
#

DISTNAME=	IO-LockedFile-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5iol
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/IO-LockedFile/
COMMENT=	Supply object methods for locking files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/LockedFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
