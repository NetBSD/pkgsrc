# $NetBSD: Makefile,v 1.2 2001/02/17 18:19:22 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	Net-TFTP-0.10
PKGNAME=	p5-Net-TFTP-0.10
WRKSRC=		${WRKDIR}/Net-TFTP-0.10
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for TFTP transfers

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/TFTP/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
