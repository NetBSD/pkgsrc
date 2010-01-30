# $NetBSD: Makefile,v 1.27 2010/01/30 16:28:00 heinz Exp $

DISTNAME=	gperf-3.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gperf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gperf/gperf.html
COMMENT=	GNU perfect hash function generator
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
