# $NetBSD: Makefile,v 1.8 2002/12/01 15:38:01 salo Exp $

DISTNAME=	sylpheed-0.8.5claws
PKGNAME=	sylpheed-claws-0.8.5
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://sylpheed-claws.sourceforge.net/
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes

CONFLICTS=	sylpheed-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILDLINK_DEPENDS.gpgme=	gpgme>=0.3.5
BUILDLINK_DEPENDS.compface=	{compface>=1.4,faces>=1.6.1nb1}

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

SUPPORT_FILES=	${FILESDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink2.mk"
.else
.  include "../../mail/faces/buildlink2.mk"
.endif
.include "../../graphics/imlib/buildlink2.mk"
.include "../../security/gpgme/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
