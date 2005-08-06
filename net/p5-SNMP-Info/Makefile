# $NetBSD: Makefile,v 1.4 2005/08/06 06:19:28 jlam Exp $
#

DISTNAME=	SNMP-Info-0.9.0
PKGNAME=	p5-SNMP-Info-0.9
PKGREVISION=	2
SVR4_PKGNAME=	p5sni
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://snmp-info.sourceforge.net/
COMMENT=	Perl5 object oriented interface to SNMP informations

DEPENDS+=	net-snmp>=5.1.2:../../net/net-snmp

WRKSRC=			${WRKDIR}/${DISTNAME:S/.0//}
PERL5_PACKLIST=		auto/SNMP/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
