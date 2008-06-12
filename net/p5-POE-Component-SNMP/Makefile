# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:40 joerg Exp $

DISTNAME=	POE-Component-SNMP-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-SNMP
COMMENT=	Event-driven SNMP interface

DEPENDS+=	p5-Net-SNMP>=5.0.1:../../net/p5-Net-SNMP

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Component/SNMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
