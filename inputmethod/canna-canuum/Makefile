# $NetBSD: Makefile,v 1.11 2010/05/28 11:06:34 obache Exp $

PKGREVISION=	3
CANNA_MODULE=	canuum

.include "../../inputmethod/canna/Makefile.common"

MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/man1

CONFIGURE_DIRS=	. canuum
BUILD_DIRS=	canuum

INSTALL_MAKE_FLAGS+=	INSTUGIDFLAGS=

SPECIAL_PERMS+=	bin/canuum ${SETUID_ROOT_PERMS}

.include "../../inputmethod/canna-lib/buildlink3.mk"

pre-configure:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/canuum
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/canuum
	${LN} -fs ${WRKSRC}/cannaconf.h ${WRKSRC}/canuum
	${LN} -fs ${WRKSRC}/canna/ccompat.h ${WRKSRC}/canuum

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
