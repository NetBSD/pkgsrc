# $NetBSD: Makefile,v 1.24 2022/06/28 11:32:35 wiz Exp $
#

DISTNAME=	IO-LockedFile-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/IO-LockedFile
COMMENT=	Supply object methods for locking files

PERL5_PACKLIST=		auto/IO/LockedFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
