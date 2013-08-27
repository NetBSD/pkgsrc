# $NetBSD: Makefile,v 1.5 2013/08/27 08:06:56 obache Exp $

DISTNAME=		Quota-1.7.0
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
