# $NetBSD: Makefile,v 1.7 2013/05/31 12:42:03 wiz Exp $

DISTNAME=	Linux-Inotify2-1.22
PKGNAME=	p5-${DISTNAME:S/22/2.2/}
PKGREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Linux-Inotify2/
COMMENT=	Scalable directory/file change notification
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

ONLY_FOR_PLATFORM=	Linux-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Linux/Inotify2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
