# $NetBSD: Makefile,v 1.42 2025/01/05 14:29:15 ktnb Exp $

DISTNAME=	pdmenu-1.3.6
CATEGORIES=	misc
MASTER_SITES=	https://git.kitenet.net/index.cgi/pdmenu.git/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://joeyh.name/code/pdmenu/
COMMENT=	Simple console menu program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run

REPLACE_PERL=	examples/showdir.pl
REPLACE_PERL+=	examples/editdir.pl

CONFIGURE_ENV+=	SLANG_LIB_LOC=${BUILDLINK_PREFIX.libslang}/lib
CONFIGURE_ENV+=	SLANG_H_LOC=${BUILDLINK_PREFIX.libslang}/include/slang.h

LDFLAGS+=	-lintl

INSTALLATION_DIRS=	share/doc/pdmenu \
			share/examples/pdmenu/newbie

INSTALL_MAKE_FLAGS+=	INSTALL_PREFIX=${DESTDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${DESTDIR}/${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	DATADIR=${DESTDIR}/share/examples/pdmenu

pre-install:
	${SED} "s,.B /etc/pdmenurc,.B ${PREFIX}/etc/pdmenurc,g"		\
		${WRKSRC}/doc/pdmenurc.man > ${WRKSRC}/doc/pdmenurc.man.done
	${MV} ${WRKSRC}/doc/pdmenurc.man.done ${WRKSRC}/doc/pdmenurc.man

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ANNOUNCE BUGS TODO \
		${DESTDIR}${PREFIX}/share/doc/pdmenu
	cd ${WRKSRC}/examples && ${INSTALL_DATA} README ba.lpd pdmenurc \
		pdmenurc.complex pdmenurc.monitor showdir.pl editdir.pl\
		${DESTDIR}${PREFIX}/share/examples/pdmenu
	cd ${WRKSRC}/examples/newbie && ${INSTALL_DATA} modem-check \
		pdmenurc.newbie	rpm-info-on-command \
		${DESTDIR}${PREFIX}/share/examples/pdmenu/newbie

CONF_FILES=	${DESTDIR}${PREFIX}/share/examples/pdmenu/pdmenurc ${PKG_SYSCONFDIR}/pdmenurc

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
