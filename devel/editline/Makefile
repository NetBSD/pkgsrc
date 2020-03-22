# $NetBSD: Makefile,v 1.8 2020/03/22 22:32:11 tnn Exp $
#

DISTNAME=		libedit-20191231-3.1
PKGNAME=		editline-3.1.20191231
CATEGORIES=		devel
MASTER_SITES=		http://thrysoee.dk/editline/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing
LICENSE=		modified-bsd

PKGCONFIG_OVERRIDE+=	libedit.pc.in

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoreconf
CONFIGURE_ARGS+=	--enable-widec

.include "../../mk/bsd.prefs.mk"

pre-configure:
.if ${OPSYS} == "SunOS" && !exists(/usr/include/err.h)
	${CP} ${FILESDIR}/err.h ${BUILDLINK_DIR}/include
.endif
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
