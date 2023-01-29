# $NetBSD: Makefile,v 1.18 2023/01/29 21:15:00 ryoon Exp $
#

DISTNAME=		WordNet-3.0
PKGREVISION=		10
CATEGORIES=		textproc
MASTER_SITES=		https://wordnetcode.princeton.edu/3.0/

PATCHFILES=		wordnet.patch.2
PATCH_SITES=		http://www.ocert.org/analysis/2008-014/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://wordnet.princeton.edu/
COMMENT=		Lexical reference system

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib

SUBST_CLASSES+=		docpath
SUBST_FILES.docpath=	doc/html/Makefile.in doc/pdf/Makefile.in
SUBST_FILES.docpath+=	doc/ps/Makefile.in
SUBST_MESSAGE.docpath=	Fixing path for documentation.
SUBST_SED.docpath=	-e 's,prefix)/doc,prefix)/share/doc/WordNet,'
SUBST_STAGE.docpath=	pre-configure

CPPFLAGS+=	-DUSE_INTERP_RESULT

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
