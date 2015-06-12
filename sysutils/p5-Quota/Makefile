# $NetBSD: Makefile,v 1.7 2015/06/12 10:51:16 wiz Exp $

DISTNAME=		Quota-1.7.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
