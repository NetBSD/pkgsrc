# $NetBSD: Makefile,v 1.7 2023/12/30 21:21:10 zafer Exp $
#

DISTNAME=		gate-2.06
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		https://www.unixpapa.com/software/

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		https://www.unixpapa.com/gate.html
COMMENT=		Lightweight text editor

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
