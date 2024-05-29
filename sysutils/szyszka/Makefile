# $NetBSD: Makefile,v 1.10 2024/05/29 16:34:32 adam Exp $

DISTNAME=	szyszka-3.0.0
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=qarmin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/qarmin/szyszka/
COMMENT=	Fast and powerful file renamer with gtk display
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk4}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.MesaLib}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.MesaLib}/lib

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	../szyszka.sh
SUBST_VARS.paths=	PREFIX

INSTALLATION_DIRS=	bin libexec/szyszka

.include "../../mk/bsd.prefs.mk"

post-extract:
	${CP} ${FILESDIR}/szyszka.sh ${WRKDIR}/szyszka.sh

# This is a workaround for PR#57445. When resolved this do-install and wrapper
# should # be removed and the binary just installed into PREFIX/bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/szyszka ${DESTDIR}${PREFIX}/libexec/szyszka
.if ${OPSYS} == "NetBSD" && ${X11_TYPE} == "native"
	${INSTALL_SCRIPT} ${WRKDIR}/szyszka.sh ${DESTDIR}${PREFIX}/bin/szyszka
.else
	${ECHO} '#!/bin/sh' > ${DESTDIR}${PREFIX}/bin/szyszka
	${ECHO} '${PREFIX}/libexec/szyszka/szyszka "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/szyszka
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/szyszka
.endif

.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
