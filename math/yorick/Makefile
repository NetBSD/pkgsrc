# $NetBSD: Makefile,v 1.2 2000/10/02 10:58:51 jlam Exp $
#

DISTNAME=	yorick-1.4
CATEGORIES=	math
MASTER_SITES=   ftp://ftp-icf.llnl.gov/pub/Yorick/

MAINTAINER=	refling@comet.lbl.gov
HOMEPAGE=	ftp://ftp-icf.llnl.gov/pub/Yorick/yorick-ad.html

GNU_CONFIGURE=  YES
USE_X11=        YES

post-install:
	cd ${WRKSRC} && ${INSTALL_MAN} yorick.1 ${PREFIX}/man/man1
	cd ${WRKSRC} && ${INSTALL_MAN} gist.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/Yorick && ${PREFIX}/bin/yorick -batch check.i

.include "../../mk/bsd.pkg.mk"
