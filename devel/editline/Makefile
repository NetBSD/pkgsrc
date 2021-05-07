# $NetBSD: Makefile,v 1.13 2021/05/07 07:13:28 nia Exp $
#

DISTNAME=		libedit-20210419-3.1
PKGNAME=		editline-3.1.20210419
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://thrysoee.dk/editline/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing
LICENSE=		modified-bsd

PKGCONFIG_OVERRIDE+=	libedit.pc.in

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoreconf
CONFIGURE_ARGS+=	--enable-widec

post-install:
	# Avoid conflict with devel/readline.
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/history.3

.include "../../mk/bsd.prefs.mk"

pre-configure:
.if ${OPSYS} == "SunOS" && !exists(/usr/include/err.h)
	${CP} ${FILESDIR}/err.h ${BUILDLINK_DIR}/include
.endif
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
