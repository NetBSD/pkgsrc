# $NetBSD: Makefile,v 1.2.4.1 2008/09/05 11:35:15 ghen Exp $
#

DISTNAME=		WordNet-3.0
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://wordnet.princeton.edu/3.0/ \
			ftp://ftp.cogsci.princeton.edu/pub/wordnet/3.0/

PATCHFILES=		wordnet.patch
PATCH_SITES=		http://www.ocert.org/analysis/2008-014/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://wordnet.princeton.edu/
COMMENT=		Lexical reference system

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
