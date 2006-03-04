# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:22 jlam Exp $

DISTNAME=	SNMP_Session-1.07
PKGNAME=	p5-SNMP_Session-1.07
SVR4_PKGNAME=	p5sns
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	http://www.switch.ch/misc/leinen/snmp/perl/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	Perl5 module providing rudimentary access to remote SNMP agents

PERL5_PACKLIST=		auto/SNMP_Session/.packlist

CONFLICTS+=	mrtg-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PERL5_INSTALLVENDORLIB}/README.SNMP_Session

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
