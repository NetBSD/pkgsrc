# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:32 veego Exp $

DISTNAME=	SNMP_Session-0.83
PKGNAME=	p5-SNMP_Session-0.83
SVR4_PKGNAME=	p5sns
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.switch.ch/software/sources/network/snmp/perl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	perl5 module providing rudimentary access to remote SNMP agents

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/SNMP_Session/.packlist

CONFLICTS+=	mrtg-[0-9]*

do-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PERL5_SITELIB}/README.SNMP_Session

.include "../../mk/bsd.pkg.mk"
