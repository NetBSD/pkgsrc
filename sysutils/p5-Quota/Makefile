# $NetBSD: Makefile,v 1.1 2012/08/14 14:24:20 dholland Exp $

DISTNAME=		Quota-1.6.7
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Quota/}

COMMENT=		Perl interface to filesystem quotas
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
