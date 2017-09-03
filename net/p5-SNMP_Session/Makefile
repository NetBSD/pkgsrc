# $NetBSD: Makefile,v 1.30 2017/09/03 08:36:58 wiz Exp $

DISTNAME=	SNMP_Session-1.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	http://snmp-session.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	Perl5 module providing rudimentary access to remote SNMP agents

PERL5_PACKLIST=		auto/SNMP_Session/.packlist

CONFLICTS+=	mrtg-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PERL5_INSTALLVENDORLIB}/README.SNMP_Session

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
