# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:19 veego Exp $

DISTNAME=	Test-Cmd-1.04
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tcm
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.baldmt.com/Test-Cmd/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.baldmt.com/Test-Cmd/
COMMENT=	perl5 module for testing of external commands and scripts

USE_PERL5=	yes

PERL5_PACKLIST+=${PERL5_SITEARCH}/auto/Test/Cmd/.packlist

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
