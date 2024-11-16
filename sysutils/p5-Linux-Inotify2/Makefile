# $NetBSD: Makefile,v 1.21 2024/11/16 12:06:39 wiz Exp $

DISTNAME=	Linux-Inotify2-2.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Linux-Inotify2
COMMENT=	Scalable directory/file change notification
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

ONLY_FOR_PLATFORM=	Linux-*-*

PERL5_PACKLIST=		auto/Linux/Inotify2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
