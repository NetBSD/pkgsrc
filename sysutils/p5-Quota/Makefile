# $NetBSD: Makefile,v 1.4 2013/05/31 12:42:03 wiz Exp $

DISTNAME=		Quota-1.6.7
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
