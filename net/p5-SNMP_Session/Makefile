# $NetBSD: Makefile,v 1.11 2005/02/09 09:04:02 seb Exp $

DISTNAME=	SNMP_Session-1.07
PKGNAME=	p5-SNMP_Session-1.07
SVR4_PKGNAME=	p5sns
CATEGORIES=	net perl5
MASTER_SITES=	http://www.switch.ch/misc/leinen/snmp/perl/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	Perl5 module providing rudimentary access to remote SNMP agents

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SNMP_Session/.packlist

CONFLICTS+=	mrtg-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PERL5_SITELIB}/README.SNMP_Session

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
