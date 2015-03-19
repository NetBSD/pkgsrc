# $NetBSD: Makefile,v 1.5 2015/03/19 19:58:28 tron Exp $
#

DISTNAME=		libedit-20140620-3.1
PKGNAME=		editline-3.1.20140620
CATEGORIES=		devel
MASTER_SITES=		http://thrysoee.dk/editline/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://www.thrysoee.dk/editline/
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
