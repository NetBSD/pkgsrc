# $NetBSD: Makefile,v 1.3 2001/02/17 18:22:50 wiz Exp $
#

DISTNAME=	yorick-1.4
CATEGORIES=	math
MASTER_SITES=   ftp://ftp-icf.llnl.gov/pub/Yorick/

MAINTAINER=	refling@comet.lbl.gov
HOMEPAGE=	ftp://ftp-icf.llnl.gov/pub/Yorick/yorick-ad.html
COMMENT=	Numerical algebra system (similar to Matlab)

GNU_CONFIGURE=  YES
USE_X11=        YES

post-install:
	cd ${WRKSRC} && ${INSTALL_MAN} yorick.1 ${PREFIX}/man/man1
	cd ${WRKSRC} && ${INSTALL_MAN} gist.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/Yorick && ${PREFIX}/bin/yorick -batch check.i

.include "../../mk/bsd.pkg.mk"
