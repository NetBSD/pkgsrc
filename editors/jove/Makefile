# $NetBSD: Makefile,v 1.18 2019/06/08 10:40:55 rillig Exp $
#

DISTNAME=	jove4.16.0.70
PKGNAME=	${DISTNAME:S/jove/jove-/}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/hugh/jove-dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Small emacs-style editor, but lacks the LISP engine

NO_CONFIGURE=	yes
USE_TOOLS+=	nroff

MAKE_ENV+=	ROOT_GROUP=${ROOT_GROUP}
MAKE_ENV+=	ROOT_USER=${ROOT_USER}
MAKE_FLAGS+=	NROFF=${NROFF:Q}

INSTALL_MAKE_FLAGS+=	JOVEHOME=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	pre-build # no pre-configure with NO_CONFIGURE...
SUBST_MESSAGE.getline=	Fixing conflict with POSIX getline.
SUBST_FILES.getline=	insert.c io.c io.h recover.c util.c util.h
SUBST_SED.getline=	-e 's/getline/get_line/'

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
