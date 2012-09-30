# $NetBSD: Makefile,v 1.9 2012/09/30 22:06:24 adam Exp $

DISTNAME=	thrulay-0.9
CATEGORIES=	benchmarks net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thrulay/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thrulay.sourceforge.net/
COMMENT=	TCP and UDP network capacity tester
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
