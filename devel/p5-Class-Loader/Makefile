# $NetBSD: Makefile,v 1.5 2003/07/17 21:32:07 grant Exp $
#

DISTNAME=		Class-Loader-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clo
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		mcr@NetBSD.org
#	from sen_ml@eccosys.com
#HOMEPAGE=	
COMMENT=		perl5 module for module loading and on-demand object creation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
