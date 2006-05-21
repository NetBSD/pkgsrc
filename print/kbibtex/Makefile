# $NetBSD: Makefile,v 1.2 2006/05/21 11:29:27 rillig Exp $

DISTNAME=		kbibtex-0.1.4
CATEGORIES=		print kde
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~fischer/kbibtex/download/
EXTRACT_SUFX=		.tar.bz2

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
