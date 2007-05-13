# $NetBSD: Makefile,v 1.37 2007/05/13 15:04:00 obache Exp $
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

# XXX: avoid to install library into ${PREFIX}/lib64 on 64-bit
SUBST_CLASSES+=		mark64
SUBST_STAGE.mark64=	pre-configure
SUBST_FILES.mark64=	Makefile.am Makefile.in
SUBST_SED.mark64=	-e 's|@MARK64@||g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
