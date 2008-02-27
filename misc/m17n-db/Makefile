# $NetBSD: Makefile,v 1.1.1.1 2008/02/27 13:45:47 obache Exp $
#

DISTNAME=	m17n-db-1.5.1
CATEGORIES=	misc
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.m17n.org/m17n-lib-en/index.html
COMMENT=	The m17n database used by the m17n library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PKGCONFIG_OVERRIDE+=	m17n-db.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
GLIBC=			glibc-2.3.6
DISTFILES=		${DEFAULT_DISTFILES} ${GLIBC}.tar.gz
SITES.${GLIBC}.tar.gz=	${MASTER_SITE_GNU:=glibc/}
CONFIGURE_ARGS+=	--with-charmaps=${WRKDIR}/${GLIBC}/localedata/charmaps
.endif

.include "../../mk/bsd.pkg.mk"
