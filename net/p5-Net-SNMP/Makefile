# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:31 veego Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=	Net-SNMP-3.60
PKGNAME=	p5-Net-SNMP-3.60
SVR4_PKGNAME=	p5nsn
WRKSRC=		${WRKDIR}/Net-SNMP-3.6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html
COMMENT=	perl5 module for SNMP queries

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/SNMP/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
