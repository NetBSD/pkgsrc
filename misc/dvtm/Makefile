# $NetBSD: Makefile,v 1.9 2013/05/21 12:34:02 adam Exp $

DISTNAME=	dvtm-0.9
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brain-dump.org/projects/dvtm/
COMMENT=	Dynamic virtual terminal manager
LICENSE=	mit

USE_LANGUAGES=		c99
NO_CONFIGURE=		yes
CURSES_DEFAULT=		ncurses

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config=	Fixing config.mk
SUBST_FILES.config=	config.mk
SUBST_SED.config=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.config+=	-e 's,share/man,${PKGMANDIR},'
SUBST_SED.config+=	-e '/LIBS/s/-lncursesw/-lncurses/'
SUBST_SED.config+=	-e 's,^CFLAGS =,CFLAGS +=,'
SUBST_SED.config+=	-e 's,^LDFLAGS =,LDFLAGS +=,'
SUBST_SED.config+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
