# $NetBSD: Makefile,v 1.82 2017/06/07 04:41:41 snj Exp $

DISTNAME=		${IRSSI_DISTNAME}
CATEGORIES=		chat
EXTRACT_SUFX=		${IRSSI_EXTRACT_SUFX}

MAINTAINER=		maya@NetBSD.org
HOMEPAGE=		http://www.irssi.org/
COMMENT=		Secure and modular IRC client with text mode user interface
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "Makefile.common"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-proxy \
			--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "options.mk"
.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi-config ${DESTDIR}${IRSSI_CONFIG}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
