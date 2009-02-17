# $NetBSD: Makefile,v 1.3 2009/02/17 10:08:15 tnn Exp $
#

DISTNAME=	dvtm-0.5.1
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.brain-dump.org/projects/dvtm/
COMMENT=	Dynamic virtual terminal manager

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_LANGUAGES=		c99
USE_NCURSES=		yes

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS =,CFLAGS +=,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS =,LDFLAGS +=,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
