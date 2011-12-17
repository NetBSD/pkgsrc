# $NetBSD: Makefile,v 1.16 2011/12/17 00:54:11 marino Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
PLIST_SUBST+=	CATMAN=man1
.else
PLIST_SUBST+=	CATMAN=cat1
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.jis	${DESTDIR}${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${DESTDIR}${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${DESTDIR}${PREFIX}/${DOCSDIR}

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
