# $NetBSD: Makefile,v 1.1.1.1 2004/03/07 17:16:54 minskim Exp $
#

DISTNAME=		ccsh-0.0.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ccsh/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ccsh.sourceforge.net/
COMMENT=		C-like syntax scripting

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes

SUBST_CLASSES+=		options
SUBST_MESSAGE.options=	"Preventing CFLAGS from being overridden."
SUBST_STAGE.options=	post-patch
SUBST_FILES.options=	Makefile
SUBST_SED.options=	-e 's,^CFLAGS =,\#CFLAGS =,g'

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccsh ${PREFIX}/bin/ccsh

.include "../../mk/bsd.pkg.mk"
