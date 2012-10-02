# $NetBSD: Makefile,v 1.10 2012/10/02 23:48:16 asau Exp $

DISTNAME=	thrulay-0.9
CATEGORIES=	benchmarks net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thrulay/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thrulay.sourceforge.net/
COMMENT=	TCP and UDP network capacity tester
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
