# $NetBSD: Makefile,v 1.11 2012/10/03 21:57:07 wiz Exp $

DISTNAME=	POE-Component-SNMP-1.1006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-SNMP
COMMENT=	Event-driven SNMP interface
LICENSE=	gnu-gpl-v2 OR artistic

DEPENDS+=	p5-Net-SNMP>=5.0.1:../../net/p5-Net-SNMP

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Component/SNMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
