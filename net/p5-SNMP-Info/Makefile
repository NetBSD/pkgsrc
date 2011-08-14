# $NetBSD: Makefile,v 1.12 2011/08/14 14:14:49 obache Exp $
#

DISTNAME=	SNMP-Info-2.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5sni
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SNMP-Info/
#HOMEPAGE=	http://snmp-info.sourceforge.net/
COMMENT=	Perl5 object oriented interface to SNMP informations
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	net-snmp>=5.1.2:../../net/net-snmp

PERL5_PACKLIST=		auto/SNMP/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
