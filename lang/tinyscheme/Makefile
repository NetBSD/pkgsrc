# $NetBSD: Makefile,v 1.18 2014/04/29 19:18:16 agc Exp $

DISTNAME=	tinyscheme-1.40
CATEGORIES=	lang
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tinyscheme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyscheme.sourceforge.net/home.html
COMMENT=	R5RS small embeddable scheme implementation
LICENSE=	modified-bsd

USE_LIBTOOL=	yes

MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin include lib share/tinyscheme

MAKE_FLAGS+=		SYS_LIBS=-lm\ ${BUILDLINK_LDADD.dl:Q}
MAKE_FLAGS+=		CC=${CC:Q} LDFLAGS=${LDFLAGS:Q} DEBUG=
MAKE_FLAGS+=		LD=${CC:Q}

SUBST_CLASSES+=		initpath
SUBST_STAGE.initpath=	pre-configure
SUBST_MESSAGE.initpath=	Fix location of init.scm file
SUBST_FILES.initpath=	scheme.c
SUBST_SED.initpath=	-e 's|@PREFIX@|${PREFIX}|'

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
