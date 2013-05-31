# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:41 wiz Exp $
#

DISTNAME=	Proc-Queue-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~salva/Proc-Queue/
COMMENT=	Limit the number of child processes running

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/Queue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
