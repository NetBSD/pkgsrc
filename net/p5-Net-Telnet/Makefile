# $NetBSD: Makefile,v 1.1 2000/05/11 15:04:59 he Exp $
#

DISTNAME=	Net-Telnet-3.01
PKGNAME=	p5-Net-Telnet-3.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
