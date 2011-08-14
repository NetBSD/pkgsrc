# $NetBSD: Makefile,v 1.18 2011/08/14 12:26:12 obache Exp $
#

DISTNAME=	IPC-ShareLite-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-ShareLite/
COMMENT=	Light-weight interface to shared memory

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/IPC/ShareLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
