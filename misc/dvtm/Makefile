# $NetBSD: Makefile,v 1.2 2008/05/25 11:46:33 tnn Exp $
#

DISTNAME=	dvtm-0.4.1
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.brain-dump.org/projects/dvtm/
COMMENT=	Dynamic virtual terminal manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c99
NO_CONFIGURE=		yes

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk...
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS =,CFLAGS +=,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS =,LDFLAGS +=,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
