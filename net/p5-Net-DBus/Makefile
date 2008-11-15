# $NetBSD: Makefile,v 1.1.1.1 2008/11/15 18:27:22 jmcneill Exp $
#

DISTNAME=	Net-DBus-0.33.6
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~danberr/Net-DBus-0.33.6/
COMMENT=	Perl extension for the DBus message system

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/DBus/.packlist

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
