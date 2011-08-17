# $NetBSD: Makefile,v 1.42 2011/08/17 07:17:15 adam Exp $

DISTNAME=	gdbm-1.9.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
