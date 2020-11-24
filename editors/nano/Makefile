# $NetBSD: Makefile,v 1.90 2020/11/24 18:21:38 nia Exp $

DISTNAME=	nano-5.3
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

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/sample.nanorc ${DESTDIR}${PREFIX}/share/examples/nano/nanorc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
