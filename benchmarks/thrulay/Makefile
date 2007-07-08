# $NetBSD: Makefile,v 1.4 2007/07/08 12:35:10 wiz Exp $

DISTNAME=	thrulay-0.8
CATEGORIES=	benchmarks net
MASTER_SITES=	http://shlang.com/thrulay/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shlang.com/thrulay/
COMMENT=	TCP and UDP network capacity tester

ONLY_FOR_PLATFORM=	DragonFly-*-i386 FreeBSD-*-i386 Linux-*-i386 \
			NetBSD-*-i386

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
