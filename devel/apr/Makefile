# $NetBSD: Makefile,v 1.82 2020/02/20 06:25:28 rin Exp $
#
# Take care, changelogs often include "PR 12345" strings
# which cause GNATS indigestion.

DISTNAME=	apr-1.7.0
PKGREVISION=	1
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
LIBS.SunOS+=		-lnsl

TEST_TARGET=		check

post-install:
	${RM} ${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${DESTDIR}${PREFIX}/libexec/apr/libtool

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
