# $NetBSD: Makefile,v 1.34 2005/06/26 20:25:48 snj Exp $

DISTNAME=		${IRSSI_DISTNAME}
PKGREVISION=		4
CATEGORIES=		chat
MASTER_SITES=		http://real.irssi.org/files/
EXTRACT_SUFX=		${IRSSI_EXTRACT_SUFX}

MAINTAINER=		mutru@iki.fi
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

.include "Makefile.common"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--with-terminfo \
			--with-proxy \
			--without-ncurses \
			--sysconfdir=${PKG_SYSCONFDIR}

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.h ${IRSSI_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/irssi-config ${IRSSI_CONFIG}

.include "../../mk/bsd.pkg.mk"
