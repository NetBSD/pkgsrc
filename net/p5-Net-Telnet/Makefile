# $NetBSD: Makefile,v 1.3 2001/02/17 18:19:23 wiz Exp $
#

DISTNAME=	Net-Telnet-3.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to use telnet

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Telnet/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
