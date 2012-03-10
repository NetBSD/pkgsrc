# $NetBSD: Makefile,v 1.78 2012/03/10 08:00:52 sbd Exp $
#

DISTNAME=	automake-1.11.3
PKGREVISION=	1
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

PLIST_SUBST+=		PKG_DIR_VERSION=1.11
GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none
INFO_FILES=		YES

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
