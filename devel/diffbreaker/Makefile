# $NetBSD: Makefile,v 1.2 2020/05/30 22:45:07 nat Exp $

PKGNAME=	diffbreaker-0.1
#PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	nat@NetBSD.org
COMMENT=	Tool to manuipulate unified diffs using curses
LICENSE=	2-clause-bsd

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/diffbreaker
USE_LANGUAGES=	c
USE_TOOLS=	make

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

INSTALLATION_DIRS=	bin
.if !empty(MANINSTALL:Mcatinstall)
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
.endif

do-extract:
	${CP} -R ${FILESDIR}/diffbreaker ${WRKDIR}

do-install:
.for f in diffbreaker
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.  if !empty(MANINSTALL:Mcatinstall)
.    if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/${f}.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/${f}.1
.    else
	${INSTALL_MAN} ${WRKSRC}/${f}.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.    endif
.  endif
.  if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
