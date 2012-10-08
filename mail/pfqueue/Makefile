# $NetBSD: Makefile,v 1.11 2012/10/08 12:19:26 asau Exp $
#

DISTNAME=	pfqueue-0.5.6
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INCOMPAT_CURSES=	NetBSD-1.*-*

.include "options.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/pfqueue

CONF_FILES=		share/examples/pfqueue/pfqueue.conf ${PKG_SYSCONFDIR}/pfqueue.conf

CONFIGURE_ARGS+=	--enable-shared

SUBST_CLASSES+=		make
SUBST_MESSAGE.make=	Fixing Makefiles for shared lib
SUBST_STAGE.make=	pre-configure
SUBST_FILES.make=	backends/Makefile.in
SUBST_FILES.make+=	libpfq/Makefile.in
SUBST_SED.make+=	-e 's,-module,,'

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing path to config file
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	pfqconfig.c pfqueue.conf.5
SUBST_SED.conf=		-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'

post-install:
	${INSTALL_DATA} ${FILESDIR}/pfqueue.conf ${DESTDIR}${PREFIX}/share/examples/pfqueue

.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
