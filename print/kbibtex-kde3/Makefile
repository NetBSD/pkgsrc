# $NetBSD: Makefile,v 1.25 2016/03/05 11:29:17 jperkin Exp $

DISTNAME=		kbibtex-0.2.1
PKGREVISION=		34
CATEGORIES=		print kde
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~fischer/kbibtex/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.unix-ag.uni-kl.de/~fischer/kbibtex/
COMMENT=		BibTeX editor for KDE

USE_TOOLS+=		gmake perl msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
