# $NetBSD: Makefile,v 1.12 2018/08/22 09:44:33 wiz Exp $
#

DISTNAME=	Proc-Queue-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~salva/Proc-Queue/
COMMENT=	Limit the number of child processes running

PERL5_PACKLIST=		auto/Proc/Queue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
