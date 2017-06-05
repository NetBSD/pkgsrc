# $NetBSD: Makefile,v 1.10 2017/06/05 14:24:36 ryoon Exp $

DISTNAME=		Quota-1.7.2
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

HOMEPAGE=		http://search.cpan.org/~tomzo/Quota/Quota.pm
COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}
# tested on NetBSD 7.99.25
LDFLAGS+=		-L/usr/lib -lquota

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
