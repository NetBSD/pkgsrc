# $NetBSD: Makefile,v 1.6 2014/05/29 23:37:30 wiz Exp $

DISTNAME=		Quota-1.7.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
