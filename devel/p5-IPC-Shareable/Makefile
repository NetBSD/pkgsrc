# $NetBSD: Makefile,v 1.5 2004/04/25 03:46:07 minskim Exp $
#

DISTNAME=	IPC-Shareable-0.60
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Tie a variable to shared memory

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Shareable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
