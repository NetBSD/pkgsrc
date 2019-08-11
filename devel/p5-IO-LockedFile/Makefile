# $NetBSD: Makefile,v 1.21 2019/08/11 13:19:37 wiz Exp $
#

DISTNAME=	IO-LockedFile-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/IO-LockedFile
COMMENT=	Supply object methods for locking files

PERL5_PACKLIST=		auto/IO/LockedFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
