# $NetBSD: Makefile,v 1.50 2007/01/24 19:46:45 epg Exp $
#

DISTNAME=	apr-1.2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	apr.pc.in

CONFIGURE_ARGS+=	\
		--with-devrandom=/dev/urandom \
		--with-installbuilddir=${PREFIX}/libexec/apr
CONFIGURE_ENV+=		LIBS=${LIBS:M*:Q}
LIBS.SunOS+=		-lnsl

TEST_TARGET=		check

post-install:
	${RM} ${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} \
		${DESTDIR}${PREFIX}/libexec/apr/libtool

.include "../../mk/bsd.pkg.mk"
