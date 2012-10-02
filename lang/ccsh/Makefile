# $NetBSD: Makefile,v 1.8 2012/10/02 20:11:36 asau Exp $
#

DISTNAME=		ccsh-0.0.4
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ccsh/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ccsh.sourceforge.net/
COMMENT=		C-like syntax scripting

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

SUBST_CLASSES+=		options
SUBST_MESSAGE.options=	Preventing CFLAGS from being overridden.
SUBST_STAGE.options=	post-patch
SUBST_FILES.options=	Makefile
SUBST_SED.options=	-e 's,^CFLAGS =,\#CFLAGS =,g'

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccsh ${DESTDIR}${PREFIX}/bin/ccsh

.include "../../mk/bsd.pkg.mk"
