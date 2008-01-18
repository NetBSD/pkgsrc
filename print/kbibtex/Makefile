# $NetBSD: Makefile,v 1.10 2008/01/18 05:08:55 tnn Exp $

DISTNAME=		kbibtex-0.1.5
PKGREVISION=		6
CATEGORIES=		print kde
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~fischer/kbibtex/download/
EXTRACT_SUFX=		.tar.bz2

PATCHFILES=		kbibtex-0.1.5-filteredselection.patch
PATCHFILES+=		kbibtex-0.1.5-gcc4.2.patch
PATCHFILES+=		kbibtex-0.1.5-viewdocument.patch
PATCH_SITES=		${MASTER_SITES}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.unix-ag.uni-kl.de/~fischer/kbibtex/
COMMENT=		BibTeX editor for KDE

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
