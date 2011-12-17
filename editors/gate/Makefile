# $NetBSD: Makefile,v 1.4 2011/12/17 10:15:24 sbd Exp $
#

DISTNAME=		gate-2.06
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		http://www.unixpapa.com/software/

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://www.unixpapa.com/gate.html
COMMENT=		Lightweight text editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
BUILD_TARGET=		# empty

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	pre-configure
SUBST_MESSAGE.getline=	Fixing conflict with POSIX getline.
SUBST_FILES.getline=	gate.h line.c main.c spel.c subs.c
SUBST_SED.getline=	-e 's/getline/get_line/'

.include	"../../mk/termcap.buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
