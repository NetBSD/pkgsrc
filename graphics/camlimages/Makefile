# $NetBSD: Makefile,v 1.3 2004/04/25 04:16:43 xtraeme Exp $

DISTNAME=		camlimages-2.11
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pauillac.inria.fr/camlimages/
COMMENT=		Image processing library for Objective Caml

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PLIST_SRC=	${PKGDIR}/PLIST

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
ALL_TARGET+=	all.opt
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.endif

.include "../../lang/ocaml/buildlink2.mk"
.include "../../x11/lablgtk/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
