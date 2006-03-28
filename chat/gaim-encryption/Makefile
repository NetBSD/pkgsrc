# $NetBSD: Makefile,v 1.10 2006/03/28 17:26:59 joerg Exp $

DISTNAME=	gaim-encryption-2.38
PKGREVISION=	2
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim-encryption/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gaim-encryption.sourceforge.net/
COMMENT=	Plugin for gaim to add TLS/SSL via nss/nspr

BUILD_USES_MSGFMT=	YES

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+=	--with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib
CONFIGURE_ARGS+=	--with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+=	--with-nss-libs=${BUILDLINK_PREFIX.nss}/lib

PTHREAD_LIB=		${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
CONFIGURE_ENV+=		PTHREAD_LIB=${PTHREAD_LIB:Q}

.include "../../chat/gaim/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
