# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:40 joerg Exp $
#

DISTNAME=	SNMP-Info-1.04
PKGNAME=	p5-SNMP-Info-1.04
SVR4_PKGNAME=	p5sni
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://snmp-info.sourceforge.net/
COMMENT=	Perl5 object oriented interface to SNMP informations

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	net-snmp>=5.1.2:../../net/net-snmp

PERL5_PACKLIST=		auto/SNMP/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
