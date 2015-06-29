# $NetBSD: Makefile,v 1.19 2015/06/29 11:06:48 ryoon Exp $

DISTNAME=	skkinput-2.06.4
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_OSDN:=skkinput2/6273/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://skkinput2.osdn.jp/
COMMENT=	X11 frontend for SKK
LICENSE=	gnu-gpl-v2

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
