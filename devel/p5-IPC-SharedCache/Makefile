# $NetBSD: Makefile,v 1.8 2005/04/11 21:45:33 tv Exp $
#

DISTNAME=	IPC-SharedCache-1.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Cache data in shared memory

DEPENDS+=	p5-IPC-ShareLite>=0.06:../../devel/p5-IPC-ShareLite

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IPC/SharedCache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
