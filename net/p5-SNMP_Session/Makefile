# $NetBSD: Makefile,v 1.8 2003/07/21 17:11:04 martti Exp $

DISTNAME=	SNMP_Session-0.83
PKGNAME=	p5-SNMP_Session-0.83
SVR4_PKGNAME=	p5sns
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.switch.ch/software/sources/network/snmp/perl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	Perl5 module providing rudimentary access to remote SNMP agents

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SNMP_Session/.packlist

CONFLICTS+=	mrtg-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PERL5_SITELIB}/README.SNMP_Session

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
