# $NetBSD: Makefile,v 1.19 2025/06/01 14:42:23 vins Exp $

DISTNAME=	libedit-20250104-3.1
PKGNAME=	editline-3.1.20250104
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://thrysoee.dk/editline/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing
LICENSE=		modified-bsd

PKGCONFIG_OVERRIDE+=	libedit.pc.in

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

post-install:
	# Install symlink like NetBSD base system has
	cd ${DESTDIR}${PREFIX}/include/editline && ln -sf readline.h history.h

.include "../../mk/bsd.prefs.mk"

pre-configure:
.if ${OPSYS} == "SunOS" && !exists(/usr/include/err.h)
	${CP} ${FILESDIR}/err.h ${BUILDLINK_DIR}/include
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
