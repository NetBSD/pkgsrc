# $NetBSD: Makefile,v 1.19 2010/08/21 16:35:32 seb Exp $

DISTNAME=	SNMP_Session-1.08
PKGNAME=	p5-SNMP_Session-1.08
PKGREVISION=	2
SVR4_PKGNAME=	p5sns
CATEGORIES=	net perl5
MASTER_SITES=	http://www.switch.ch/misc/leinen/snmp/perl/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.switch.ch/misc/leinen/snmp/perl/
COMMENT=	Perl5 module providing rudimentary access to remote SNMP agents

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/SNMP_Session/.packlist

CONFLICTS+=	mrtg-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PERL5_INSTALLVENDORLIB}/README.SNMP_Session

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
