# $NetBSD: Makefile,v 1.12 2011/12/16 17:18:52 marino Exp $

DISTNAME=	p2c-1.20
CATEGORIES=	lang
MASTER_SITES=	ftp://csvax.cs.caltech.edu/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pascal to C compiler (translates Pascal to C)
LICENSE=	gnu-gpl-v1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/src
CFLAGS+=	-Dunix=1

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

post-extract:
	# fix work dir permissions, set to 777 after extraction (why?)
	${CHMOD} 755 ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
