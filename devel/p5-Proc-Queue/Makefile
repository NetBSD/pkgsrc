# $NetBSD: Makefile,v 1.17 2022/06/28 11:33:08 wiz Exp $
#

DISTNAME=	Proc-Queue-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Proc-Queue
COMMENT=	Limit the number of child processes running

PERL5_PACKLIST=		auto/Proc/Queue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
