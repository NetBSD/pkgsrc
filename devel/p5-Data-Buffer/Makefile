# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:47 jlam Exp $
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

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Buffer/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
