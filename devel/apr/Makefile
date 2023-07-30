# $NetBSD: Makefile,v 1.93 2023/07/30 21:31:50 tnn Exp $
#
# Take care, changelogs often include "PR 12345" strings
# which cause GNATS indigestion.

DISTNAME=	apr-1.7.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://apr.apache.org/
COMMENT=	Apache Portable Runtime
LICENSE=	apache-2.0

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	apr.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-devrandom=/dev/urandom
CONFIGURE_ARGS+=	--with-installbuilddir=${PREFIX}/libexec/apr
CONFIGURE_ENV+=		LIBS=${LIBS:M*:Q}
CONFIGURE_ENV.NetBSD+=	apr_cv_epoll=no
LIBS.SunOS+=		-lnsl
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
REPLACE_SH+=		apr-config.in
.endif

post-install:
	${RM} ${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${DESTDIR}${PREFIX}/libexec/apr/libtool

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
