# $NetBSD: Makefile,v 1.22 2010/01/16 23:37:49 heinz Exp $

DISTNAME=	autoconf-2.13
PKGNAME=	autoconf213-2.13
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts (old version)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gm4:run makeinfo perl:run

CONFLICTS=		autoconf-devel-[0-9]*
CONFLICTS=		autoconf<2.50

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.13/'
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
