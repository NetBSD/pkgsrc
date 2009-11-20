# $NetBSD: Makefile,v 1.8 2009/11/20 13:14:13 fhajny Exp $
#

DISTNAME=	pfqueue-0.5.6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INCOMPAT_CURSES=	NetBSD-1.*-*

.include "options.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFIGURE_ARGS+=	--enable-shared

SUBST_CLASSES+=		make
SUBST_MESSAGE.make=	Fixing Makefiles for shared lib
SUBST_STAGE.make=	pre-configure
SUBST_FILES.make=	backends/Makefile.in
SUBST_FILES.make+=	libpfq/Makefile.in
SUBST_SED.make+=	-e 's,-module,,'

.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
