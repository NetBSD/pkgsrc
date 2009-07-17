# $NetBSD: Makefile,v 1.6 2009/07/17 18:00:13 adrianp Exp $
#

DISTNAME=	POE-Filter-IRCD-2.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Filter-IRCD/
COMMENT=	POE-based parser for the IRC protocol

DEPENDS+=	p5-POE>=0.3202:../../devel/p5-POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Filter/IRCD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
