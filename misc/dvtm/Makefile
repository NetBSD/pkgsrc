# $NetBSD: Makefile,v 1.1.1.1 2008/03/09 17:20:47 tnn Exp $
#

DISTNAME=	dvtm-0.4
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.brain-dump.org/projects/dvtm/
COMMENT=	Dynamic virtual terminal manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c99
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvtm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvtm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
