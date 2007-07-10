# $NetBSD: Makefile,v 1.14.8.1 2007/07/10 09:37:03 ghen Exp $

DISTNAME=	gaim-encryption-2.39
#PKGREVISION=	3
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-encrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gaim-encryption.sourceforge.net/
COMMENT=	Plugin for gaim to add TLS/SSL via nss/nspr

USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	# empty

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
