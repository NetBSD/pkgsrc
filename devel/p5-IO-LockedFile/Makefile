# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:32 tv Exp $
#

DISTNAME=	IO-LockedFile-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iol
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/IO-LockedFile/
COMMENT=	Supply object methods for locking files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/LockedFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
