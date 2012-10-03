# $NetBSD: Makefile,v 1.22 2012/10/03 00:02:40 asau Exp $
#

DISTNAME=	licq-1.3.5
PKGNAME=	${DISTNAME:C/-/-gui-console-/}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	Curses GUI for licq

DEPENDS+=	licq-core-[0-9]*:../../chat/licq-core

DISTINFO_FILE=		${.CURDIR}/../../chat/licq-core/distinfo
PATCHDIR=		${.CURDIR}/../../chat/licq-core/patches

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty
CONFIGURE_DIRS=		plugins/console
OVERRIDE_DIRDEPTH=	3

INCOMPAT_CURSES=	NetBSD-1.4*-* NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-Q]-*

# the cdk on NetBSD 4.0 isn't compatible; also force the check
# initCDKScreen() to succeed, the configure script test fails due
# to missing -lm
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
USE_BUILTIN.cdk=	no
CONFIGURE_ENV+=		ac_cv_lib_cdk_initCDKScreen="yes"
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/cdk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
