# $NetBSD: Makefile,v 1.96 2021/04/23 17:05:26 thor Exp $

DISTNAME=	nano-5.6.1
CATEGORIES=	editors
MASTER_SITES=	https://www.nano-editor.org/dist/v${PKGVERSION_NOREV:C/\..*$//}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://www.nano-editor.org/
COMMENT=	Small and friendly text editor (a free replacement for Pico)
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt msgmerge xgettext gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-color
CONFIGURE_ARGS+=	--enable-multibuffer
CONFIGURE_ARGS+=	--enable-nanorc
CONFIGURE_ARGS+=	--enable-extra
# Help it find our preferrend ncursesw using pkg-config instead
# of resorting to outdated ncursesw5-config in host system on SLES 11.
CONFIGURE_ARGS+=        PKG_CONFIG=pkg-config

INFO_FILES=		yes

# Looks like that IRIX 5.x lacks vsnprintf() functions,
# which are required to make this work, so glib2 is used instead.
.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
.  include "../../devel/glib2/buildlink3.mk"
.endif

.include "options.mk"

INSTALLATION_DIRS+=	share/examples/nano
CONF_FILES+=		share/examples/nano/nanorc ${PKG_SYSCONFDIR}/nanorc

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing paths in manpages.
SUBST_FILES.man=	doc/nano.1 doc/nanorc.5
SUBST_VARS.man=		PKG_SYSCONFDIR PREFIX

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/sample.nanorc ${DESTDIR}${PREFIX}/share/examples/nano/nanorc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
