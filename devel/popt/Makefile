# $NetBSD: Makefile,v 1.36 2007/05/12 00:52:28 obache Exp $
#

DISTNAME=	popt-1.10.7
CATEGORIES=	devel
MASTER_SITES=	http://wraptastic.org/pub/rpm-4.4.x/		\
		ftp://wraptastic.org/pub/rpm-4.4.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command line option parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		ORBit<=0.5.3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

TEST_TARGET=		check

# XXX: avoid to check GNU xgettext.
post-extract:
	touch ${WRKDIR}/rpm.c

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
