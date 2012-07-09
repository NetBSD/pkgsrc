# $NetBSD: Makefile,v 1.84 2012/07/09 18:03:49 bsiegert Exp $
#

# Note: when the minor version changes (e.g. 1.11 -> 1.12)
# emulators/b-em/hacks.mk needs to be updated for the new version.
# Please do so when updating automake as otherwise pbulk will choke.
# (It should be safe to make the change blindly.)

DISTNAME=	automake-1.12.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/} \
		ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator
LICENSE=	gnu-gpl-v2

DEPENDS+=	autoconf>=2.62:../../devel/autoconf

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gm4:run perl:run

PLIST_SUBST+=		PKG_DIR_VERSION=1.12
GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none
INFO_FILES=		YES
REPLACE_PERL=		lib/tap-driver.pl

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
