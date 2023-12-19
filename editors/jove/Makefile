# $NetBSD: Makefile,v 1.21 2023/12/19 01:00:27 gutteridge Exp $

DISTNAME=	jove4.16.0.74
PKGNAME=	${DISTNAME:S/jove/jove-/}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/hugh/jove-dev/experimental/
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
CFLAGS.NetBSD+=		-DUSE_OPENPTY -DNO_TIOCREMOTE
LDFLAGS.NetBSD+=	-lutil

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	pre-build # no pre-configure with NO_CONFIGURE...
SUBST_MESSAGE.getline=	Fixing conflict with POSIX getline.
SUBST_FILES.getline=	insert.c io.c io.h recover.c util.c util.h
SUBST_SED.getline=	-e 's/getline/get_line/'

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
