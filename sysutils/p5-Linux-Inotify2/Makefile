# $NetBSD: Makefile,v 1.1.1.1 2010/02/23 13:51:34 sno Exp $

DISTNAME=	Linux-Inotify2-1.21
PKGNAME=	p5-${DISTNAME:S/21/2.1/}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Linux-Inotify2/
COMMENT=	Scalable directory/file change notification
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

ONLY_FOR_PLATFORM=	Linux-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Linux/Inotify2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
