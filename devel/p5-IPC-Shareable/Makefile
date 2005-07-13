# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:26 jlam Exp $
#

DISTNAME=	IPC-Shareable-0.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Tie a variable to shared memory

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IPC/Shareable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
