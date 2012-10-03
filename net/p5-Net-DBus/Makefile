# $NetBSD: Makefile,v 1.6 2012/10/03 21:57:00 wiz Exp $
#

DISTNAME=	Net-DBus-1.0.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-DBus/
COMMENT=	Perl extension for the DBus message system
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=		auto/Net/DBus/.packlist

DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig

# documented requirement
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0.0
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
