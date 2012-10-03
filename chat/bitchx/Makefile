# $NetBSD: Makefile,v 1.51 2012/10/03 00:02:34 asau Exp $

DISTNAME=	ircii-pana-1.1-final
PKGNAME=	bitchx-1.1
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bitchx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

# This package is not even remotely 64-bit clean
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

USE_TOOLS+=	bash

WRKSRC=			${WRKDIR}/BitchX
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl
CONFIG_SHELL=		${TOOLS_PATH.bash}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=	-DBIND_8_COMPAT
.endif

SUBST_CLASSES+=		manpage
SUBST_STAGE.manpage=	post-patch
SUBST_FILES.manpage+=	doc/BitchX.1
SUBST_SED.manpage+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
