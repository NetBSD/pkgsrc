# $NetBSD: Makefile,v 1.115 2009/05/02 16:21:44 reed Exp $

DISTNAME=	sylpheed-2.6.0
CATEGORIES=	mail news x11
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/v2.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://sylpheed.sraoss.jp/en/
COMMENT=	X based e-mail and netnews client

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS=		sylpheed-claws-[0-9]*

PREV_PKGPATH=		mail/sylpheed-devel

USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-compface

PKG_SYSCONFSUBDIR=	sylpheed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/sylpheed
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${DESTDIR}${EGDIR}

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
