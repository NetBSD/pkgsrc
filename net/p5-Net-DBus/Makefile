# $NetBSD: Makefile,v 1.13 2016/08/01 12:35:58 mef Exp $
#

DISTNAME=	Net-DBus-1.1.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-DBus/
COMMENT=	Perl extension for the DBus message system
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=		auto/Net/DBus/.packlist

DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig

# documented requirement
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0.0
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
