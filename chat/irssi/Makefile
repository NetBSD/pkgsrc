# $NetBSD: Makefile,v 1.93 2019/08/11 13:18:03 wiz Exp $

DISTNAME=		${IRSSI_DISTNAME}
PKGREVISION=		1
CATEGORIES=		chat
EXTRACT_SUFX=		${IRSSI_EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.irssi.org/
COMMENT=		Secure and modular IRC client with text mode user interface
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "Makefile.common"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
TEST_TARGET=		check

CONFIGURE_ARGS+=	--with-proxy \
			--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

OPSYSVARS+=		MODULEEXT
MODULEEXT.Darwin=	bundle
MODULEEXT.*=		so
PLIST_SUBST+=		MODULEEXT=${MODULEEXT}

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "options.mk"
.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi-config ${DESTDIR}${IRSSI_CONFIG}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
