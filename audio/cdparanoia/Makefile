# $NetBSD: Makefile,v 1.5 2001/12/03 17:57:44 wiz Exp $

DISTNAME=	cdparanoia-III-alpha9.7
PKGNAME=	cdparanoia-3.0.9.7
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/paranoia/download/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xiph.org/paranoia/
COMMENT=	CDDA reading utility with extra data verification features

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
MAKE_ENV+=	GCC=yes

#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/cdparanoia ${PREFIX}/bin
#	${INSTALL_MAN} ${WRKSRC}/cdparanoia.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
