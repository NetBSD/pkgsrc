# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:27 jschauma Exp $
#

DISTNAME=	IPC-Shareable-0.60
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Tie a variable to shared memory

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable

USE_BUILDLINK2=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IPC/Shareable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
