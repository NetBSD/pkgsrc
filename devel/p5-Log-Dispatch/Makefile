# $NetBSD: Makefile,v 1.2 2001/06/06 13:18:57 mjl Exp $

DISTNAME=	Log-Dispatch-1.79
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl module for logging messages to multiple outputs

USE_PERL5=      # defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Log/Dispatch/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
