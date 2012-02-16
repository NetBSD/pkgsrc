# $NetBSD: Makefile,v 1.13 2012/02/16 15:26:41 hans Exp $
#

DISTNAME=	licq-1.3.5
PKGNAME=	${DISTNAME:C/-/-core-/}
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	msgmerge msgfmt
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--localedir=${LOCALBASE}/${PKGLOCALEDIR}/locale

.include "../../mk/bsd.prefs.mk"

# Make sure modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
