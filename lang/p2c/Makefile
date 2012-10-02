# $NetBSD: Makefile,v 1.15 2012/10/02 20:11:47 asau Exp $

DISTNAME=	p2c-1.20
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://csvax.cs.caltech.edu/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pascal to C compiler (translates Pascal to C)
LICENSE=	gnu-gpl-v1

WRKSRC=		${WRKDIR}/src
CFLAGS+=	-Dunix=1

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

post-extract:
	# The distfile contains a number of world-writable files, including
	# an entry for '.' that causes pkgsrc to become upset. Fix it.
	${CHMOD} 755 ${WRKDIR}
	${CHMOD} -R o-w ${WRKDIR}/*

.include "../../mk/bsd.pkg.mk"
