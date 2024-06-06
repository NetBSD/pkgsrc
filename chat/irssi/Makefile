# $NetBSD: Makefile,v 1.109 2024/06/06 11:03:28 jperkin Exp $

DISTNAME=		irssi-1.4.5
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=irssi/}
GITHUB_RELEASE=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.irssi.org/
COMMENT=		Secure and modular IRC client with text mode user interface
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
TEST_TARGET=		check

CONFIGURE_ARGS+=	--with-proxy
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

OPSYSVARS+=		MODULEEXT
MODULEEXT.Darwin=	bundle
MODULEEXT.*=		so
PLIST_SUBST+=		MODULEEXT=${MODULEEXT}

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
