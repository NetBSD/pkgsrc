# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:13 veego Exp $
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

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Buffer/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
