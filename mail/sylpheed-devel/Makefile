# $NetBSD: Makefile,v 1.28 2006/01/24 07:32:19 wiz Exp $

DISTNAME=	sylpheed-2.2.0beta5
PKGREVISION=	1
CATEGORIES=	mail news x11
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/v2.2beta/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes
DEPENDS+=		metamail>=2.7:../../mail/metamail

CONFLICTS=		sylpheed-claws-[0-9]* sylpheed-gtk2-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=            yes
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-compface

PKG_SYSCONFSUBDIR=	sylpheed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/sylpheed
CONF_FILES=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mime.types ${EGDIR}

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
