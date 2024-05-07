# $NetBSD: Makefile,v 1.9 2024/05/07 11:46:00 nat Exp $

VERSION=	0.5
GITHUB_PROJECT= diffbreaker
DISTNAME=       ${GITHUB_PROJECT}-${VERSION}
PKGNAME=        ${GITHUB_PROJECT}-${VERSION}

#PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GITHUB:=AceHusky12/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nat@NetBSD.org
HOMEPAGE=	https://github.com/AceHusky12/diffbreaker
COMMENT=	Tool to manuipulate unified diffs using curses
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

INSTALLATION_DIRS=	bin
.if !empty(MANINSTALL:Mcatinstall)
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
.endif

do-install:
.for f in diffbreaker
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
