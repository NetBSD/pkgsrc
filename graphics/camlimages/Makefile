# $NetBSD: Makefile,v 1.20 2008/04/12 22:43:01 jlam Exp $

DISTNAME=		camlimages-2.2.0
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pauillac.inria.fr/camlimages/
COMMENT=		Image processing library for Objective Caml

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.0.6

WRKSRC=			${WRKDIR}/camlimages-2.2
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		${PKGDIR}/PLIST

CONFIGURE_ARGS+=	--with-lablgtk=${PREFIX}/lib/ocaml/lablgtk

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=	all
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.endif

PLIST_VARS+=	dll
.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "Darwin" || ${OPSYS} == "NetBSD"
PLIST.dll=	yes
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/lablgtk1/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/ocaml-graphics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
