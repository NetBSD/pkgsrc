# $NetBSD: Makefile,v 1.1.1.1 2001/02/27 21:09:53 jtb Exp $

DISTNAME=	SNMP_Session-0.83
PKGNAME=	p5-SNMP_Session-0.83
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.switch.ch/software/sources/network/snmp/perl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	perl5 module providing rudimentary access to remote SNMP agents

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/SNMP_Session/.packlist

do-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PERL5_SITELIB}/README.SNMP_Session

.include "../../mk/bsd.pkg.mk"
