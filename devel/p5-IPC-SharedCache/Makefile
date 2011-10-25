# $NetBSD: Makefile,v 1.16 2011/10/25 09:22:32 hiramatsu Exp $
#

DISTNAME=	IPC-SharedCache-1.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-SharedCache/
COMMENT=	Cache data in shared memory
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-IPC-ShareLite>=0.06:../../devel/p5-IPC-ShareLite

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/IPC/SharedCache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
