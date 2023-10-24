# $NetBSD: Makefile,v 1.43 2023/10/24 22:08:20 wiz Exp $

DISTNAME=	eggdrop-1.9.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://ftp.eggheads.org/pub/eggdrop/source/${PKGVERSION_NOREV:R}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.eggheads.org/
COMMENT=	IRC robot with TCL scripting and multi-channel ability
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/eggdrop
CONF_FILES=	${EGDIR}/eggdrop.conf ${PKG_SYSCONFDIR}/eggdrop.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}
INSTALLATION_DIRS+=	lib/eggdrop
INSTALLATION_DIRS+=	share/doc
INSTALLATION_DIRS+=	share/eggdrop
INSTALLATION_DIRS+=	share/examples/eggdrop

SUBST_CLASSES+=		dir
SUBST_FILES.dir=	eggdrop.conf
SUBST_STAGE.dir=	pre-configure
SUBST_SED.dir+=		-e 's,modules/,${PREFIX}/lib/eggdrop/,'
SUBST_SED.dir+=		-e 's,source scripts/,source ${PREFIX}/share/eggdrop/scripts/,'
SUBST_SED.dir+=		-e 's,set help-path .*,set help-path "${PREFIX}/share/eggdrop/help/",'
SUBST_SED.dir+=		-e 's,set text-path .*,set text-path "${PREFIX}/share/eggdrop/text/",'
SUBST_SED.dir+=		-e 's,set motd .*,set motd "${PREFIX}/share/eggdrop/text/motd",'
SUBST_SED.dir+=		-e 's,set telnet-banner .*,set telnet-banner "${PREFIX}/share/eggdrop/text/banner",'

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		TCLLIB="${PREFIX}/lib" TCLINC="${PREFIX}/include"

CFLAGS+=		-DLANGDIR=\"${PREFIX}/share/eggdrop/language\"

BUILD_TARGET=	eggdrop

post-configure:
	cd ${WRKSRC} && ${MAKE} config

do-install:
	cd "${WRKSRC}" && ${SETENV} ${MAKE_ENV} ${MAKE} DEST=${WRKDIR}/eggdrop install
	${INSTALL_PROGRAM} ${WRKDIR}/eggdrop/${DISTNAME} ${DESTDIR}${PREFIX}/bin/eggdrop
	cd ${WRKDIR}/eggdrop && ${PAX} -rw -pp help language scripts text \
		${DESTDIR}${PREFIX}/share/eggdrop/
	cd ${WRKDIR}/eggdrop/doc && ${PAX} -rw -pp * ${DESTDIR}${PREFIX}/share/doc/eggdrop/
	mv -f ${DESTDIR}${PREFIX}/share/doc/eggdrop/man1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf ${DESTDIR}${EGDIR}/eggdrop.conf
	${INSTALL_LIB} ${WRKDIR}/eggdrop/modules/* \
		${DESTDIR}${PREFIX}/lib/eggdrop

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
