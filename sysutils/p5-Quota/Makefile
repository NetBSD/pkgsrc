# $NetBSD: Makefile,v 1.12 2019/07/01 21:35:52 nia Exp $

DISTNAME=		Quota-1.7.2
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

HOMEPAGE=		https://metacpan.org/pod/distribution/Quota/Quota.pm
COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}
# tested on NetBSD 7.99.25
LDFLAGS+=		-L/usr/lib -lquota

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
