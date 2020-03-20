# $NetBSD: Makefile,v 1.12 2020/03/20 11:57:55 nia Exp $
#

DISTNAME=		ccsh-0.0.4
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ccsh/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ccsh.sourceforge.net/
COMMENT=		C-like syntax scripting

USE_TOOLS+=		gmake

SUBST_CLASSES+=		options
SUBST_MESSAGE.options=	Preventing CFLAGS from being overridden.
SUBST_STAGE.options=	pre-configure
SUBST_FILES.options=	Makefile
SUBST_SED.options=	-e 's,^CFLAGS =,\#CFLAGS =,g'

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccsh ${DESTDIR}${PREFIX}/bin/ccsh

.include "../../mk/bsd.pkg.mk"
