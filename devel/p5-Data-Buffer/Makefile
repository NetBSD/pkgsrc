# $NetBSD: Makefile,v 1.4 2002/10/13 22:22:51 seb Exp $
#

DISTNAME=		Data-Buffer-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dbu
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		mcr@netbsd.org
#	from sen_ml@eccosys.com
#HOMEPAGE=	
COMMENT=		perl5 module for low-level binary buffer

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Buffer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
