# $NetBSD: Makefile,v 1.2 2001/10/23 19:27:31 veego Exp $

DISTNAME=		Convert-UUlib-0.201
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uul
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to the uulib library

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/UUlib/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
