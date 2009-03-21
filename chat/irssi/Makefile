# $NetBSD: Makefile,v 1.51 2009/03/21 16:28:05 darcy Exp $

DISTNAME=		${IRSSI_DISTNAME}
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		http://www.irssi.org/files/
EXTRACT_SUFX=		${IRSSI_EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.irssi.org/
COMMENT=		Secure and modular IRC client with text mode user interface

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "Makefile.common"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-terminfo \
			--with-proxy \
			--without-ncurses \
			--sysconfdir=${PKG_SYSCONFDIR:Q}

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=YES
.endif

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.h ${DESTDIR}${IRSSI_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/irssi-config ${DESTDIR}${IRSSI_CONFIG}

.include "../../mk/bsd.pkg.mk"
