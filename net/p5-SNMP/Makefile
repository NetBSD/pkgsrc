# $NetBSD: Makefile,v 1.18 2004/02/13 17:46:22 seb Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/06/27 01:53:13 jfitz Exp
#

DISTNAME=	net-snmp-5.0.9
PKGNAME=	p5-SNMP-5.0.9
SVR4_PKGNAME=	p5snm
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=net-snmp/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.net-snmp.org/
COMMENT=	Perl5 module for interfacing to the Net-SNMP library

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Bundle/NetSNMP/.packlist

WRKSRC=		${WRKDIR}/${DISTNAME}/perl

INSTALLATION_DIRS+=	share/doc/p5-SNMP

post-install:
	${INSTALL_DATA} ${WRKSRC}/SNMP/README ${PREFIX}/share/doc/p5-SNMP/README

.include "../../lang/perl5/module.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
