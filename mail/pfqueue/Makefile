# $NetBSD: Makefile,v 1.19 2020/06/02 08:24:15 adam Exp $
#

DISTNAME=	pfqueue-0.5.6
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
FAKE_NCURSES=	yes

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
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	pfqconfig.c pfqueue.conf.5
SUBST_VARS.conf=	PKG_SYSCONFDIR

post-install:
	${INSTALL_DATA} ${FILESDIR}/pfqueue.conf ${DESTDIR}${PREFIX}/share/examples/pfqueue

.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
