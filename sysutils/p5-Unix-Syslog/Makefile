# $NetBSD: Makefile,v 1.1.1.1 2001/10/22 05:48:08 martti Exp $

DISTNAME=		Syslog-0.95
PKGNAME=		p5-Unix-${DISTNAME}
SVR4_PKGNAME=		p5sl
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Unix}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to the UNIX system logger

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unix/Syslog/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
