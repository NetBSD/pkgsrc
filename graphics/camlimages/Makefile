# $NetBSD: Makefile,v 1.8 2005/02/04 22:07:24 adrianp Exp $

DISTNAME=		camlimages-2.2.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pauillac.inria.fr/camlimages/
COMMENT=		Image processing library for Objective Caml

BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.0.6

WRKSRC=                 ${WRKDIR}/camlimages-2.2
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		${PKGDIR}/PLIST

CONFIGURE_ARGS+=	--with-lablgtk=${PREFIX}/lib/ocaml/lablgtk

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=	all
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.endif

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.Darwin
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/ocaml-graphics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
