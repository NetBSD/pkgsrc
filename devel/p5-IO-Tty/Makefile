# $NetBSD: Makefile,v 1.5 2001/02/27 22:46:08 wiz Exp $
#

DISTNAME=	IO-Tty-0.04
PKGNAME=	p5-${DISTNAME:C/T/t/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO/Tty/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
