# $NetBSD: Makefile,v 1.6 2003/07/30 14:50:08 jmmv Exp $

DISTNAME=	freeradius-0.7
CATEGORIES=	net
PKGREVISION=	3
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.freeradius.org/
COMMENT=	Free RADIUS server implementation

CONFLICTS+=	radiusd-cistron*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2= YES
USE_LIBTOOL=	YES
USE_PKGINSTALL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS=		--quiet
CONFIGURE_ARGS+=	--with-logdir=/var/log
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	--with-ltdl-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ltdl-include=${PREFIX}/include
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

RCD_SCRIPTS=		radiusd

OWN_DIRS=		/var/run/radiusd

PKG_SYSCONFSUBDIR=	raddb
EGDIR=			${PREFIX}/share/examples/freeradius
CONF_FILES=		# Contents set in HEADER file

.include "../../mk/bsd.prefs.mk"

# Needs semaphore functions as well as thread libs.
.if ${OPSYS} == "NetBSD"
.  if ${OS_VERSION:M1.[0-5]*} || ${OS_VERSION} == "1.6" || ${OS_VERSION:M1.6[A-M]*} || ${OS_VERSION:M1.6.1*}
CONFIGURE_ARGS+=	--with-threads=no
.  endif
.endif

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/raddb && for f in [a-z]*; do \
		${INSTALL_DATA} $$f ${EGDIR}/$$f; \
	done

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
