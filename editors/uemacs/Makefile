# $NetBSD: Makefile,v 1.14 2012/05/10 20:59:41 dholland Exp $

DISTNAME=	ue400dev
PKGNAME=	uemacs-4.0
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://aquest.com/pub/uemacs400/disk2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	"emacs" key sequences compatible full screen editor

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/uemacs

WRKSRC=		${WRKDIR}
EXTRACT_OPTS_ZIP=	-Laqo

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/bind.c h/epath.h
SUBST_SED.paths=	-e s,%%PREFIX%%,${PREFIX},g

post-extract:
	${CP} -r ${WRKSRC}/freebsd ${WRKSRC}/netbsd

.include "../../mk/bsd.pkg.mk"
