# $NetBSD: Makefile,v 1.1.1.1 2000/08/03 17:49:25 rh Exp $
#

DISTNAME=	yorick-1.4
CATEGORIES=	math
MASTER_SITES=   ftp://ftp-icf.llnl.gov/pub/Yorick/

MAINTAINER=	refling@comet.lbl.gov
HOMEPAGE=	ftp://ftp-icf.llnl.gov/pub/Yorick/yorick-ad.html

GNU_CONFIGURE=  YES
USE_X11=        YES

post-install:
	(cd ${WRKSRC}; ${INSTALL_MAN} yorick.1 ${PREFIX}/man/man1)
	(cd ${WRKSRC}; ${INSTALL_MAN} gist.1 ${PREFIX}/man/man1)
	(cd ${WRKSRC}/Yorick; ${PREFIX}/bin/yorick -batch check.i)

.include "../../mk/bsd.pkg.mk"
