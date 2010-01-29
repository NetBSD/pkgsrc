# $NetBSD: Makefile,v 1.14 2010/01/29 19:47:01 joerg Exp $
#

DISTNAME=	jove4.16.0.70
PKGNAME=	${DISTNAME:S/jove/jove-/}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/hugh/jove-dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Small emacs-style editor, but lacks the LISP engine

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_TOOLS+=	nroff

MAKE_ENV+=	ROOT_GROUP=${ROOT_GROUP:Q}
MAKE_ENV+=	ROOT_USER=${ROOT_USER:Q}
MAKE_FLAGS+=	NROFF=${NROFF:Q}

INSTALL_MAKE_FLAGS+=	JOVEHOME=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
