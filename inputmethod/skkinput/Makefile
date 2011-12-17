# $NetBSD: Makefile,v 1.17 2011/12/17 10:57:56 obache Exp $

DISTNAME=	skkinput-2.06.4
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skkinput2/6273/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://skkinput2.sourceforge.jp/
COMMENT=	X11 frontend for SKK
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	IPV6_READY

USE_IMAKE=	YES

DOCSDIR=	share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCSDIR}

PLIST_SUBST+=	IMAKE_JMAN_DIR=${IMAKE_MAN_DIR:ts/:H}/ja_JP.EUC/${IMAKE_MAN_DIR:ts/:T}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.jis	${DESTDIR}${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${DESTDIR}${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${DESTDIR}${PREFIX}/${DOCSDIR}

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
