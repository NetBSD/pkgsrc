# $NetBSD: Makefile,v 1.3 2004/10/03 00:15:02 tv Exp $
#

DISTNAME=		open-cobol-0.23
PKGNAME=		${DISTNAME:S/-//}
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://open-cobol.sourceforge.net/
COMMENT=		Open-source COBOL compiler

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		open-cobol.info

CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--with-lfs

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/libconf.conf ${PKG_SYSCONFDIR}/libconf.conf

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES=		lnk
SUBST_STAGE.lnk=	post-patch
SUBST_FILES.lnk=	configure
SUBST_SED.lnk=		-e "s|COBC_LIBS=\"\"|COBC_LIBS=\"\$$LDFLAGS\"|g" \
			-e "s|LIBCOB_LIBS=\"-lm\"|LIBCOB_LIBS=\"-lm \$$LDFLAGS\"|g"
.if ${OPSYS} == "NetBSD"
SUBST_SED.lnk+=		-e "s,-lncurses,-lcurses,g"
.endif
SUBST_MESSAGE.lnk=	"Fixing linking flags."

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
