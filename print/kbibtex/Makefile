# $NetBSD: Makefile,v 1.4 2006/11/20 10:23:15 markd Exp $

DISTNAME=		kbibtex-0.1.5
PKGREVISION=		1
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

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
