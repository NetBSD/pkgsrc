# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:49 tv Exp $

DISTNAME=		camlimages-2.11
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pauillac.inria.fr/camlimages/
COMMENT=		Image processing library for Objective Caml

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PLIST_SRC=	${PKGDIR}/PLIST

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
ALL_TARGET+=	all.opt
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
