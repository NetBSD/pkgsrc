# $NetBSD: Makefile,v 1.15 2020/03/26 13:31:42 nia Exp $

DISTNAME=	dvtm-0.15
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brain-dump.org/projects/dvtm/
COMMENT=	Dynamic virtual terminal manager
LICENSE=	mit

USE_CURSES=	wide
USE_LANGUAGES=	c99

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing config.mk
SUBST_FILES.config=	config.mk
SUBST_SED.config=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.config+=	-e 's,share/man,${PKGMANDIR},'
SUBST_SED.config+=	-e '/LIBS/s/-lncursesw/-lcurses/'
SUBST_SED.config+=	-e 's,^CFLAGS =,CFLAGS +=,'
SUBST_SED.config+=	-e 's,^LDFLAGS =,LDFLAGS +=,'
SUBST_SED.config+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
