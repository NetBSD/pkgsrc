# $NetBSD: Makefile,v 1.36 2019/08/11 13:21:59 wiz Exp $
#

DISTNAME=	pdmenu_1.2.65
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	http://www.kitenet.net/programs/pdmenu/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kitenet.net/~joey/code/pdmenu.html
COMMENT=	Simple console menu program

WRKSRC=		${WRKDIR}/pdmenu
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run

REPLACE_PERL=	examples/showdir.pl


CONFIGURE_ENV+=	SLANG_LIB_LOC=${BUILDLINK_PREFIX.libslang:Q}/lib
CONFIGURE_ENV+=	SLANG_H_LOC=${BUILDLINK_PREFIX.libslang:Q}/include/slang.h

INSTALLATION_DIRS=	lib/pdmenu share/doc/pdmenu \
			share/examples/pdmenu/newbie

INSTALL_MAKE_FLAGS+=	INSTALL_PREFIX=${DESTDIR}

pre-install:
	${SED} "s,.B /etc/pdmenurc,.B ${PREFIX}/etc/pdmenurc,g"		\
		${WRKSRC}/doc/pdmenurc.man > ${WRKSRC}/doc/pdmenurc.man.done
	${MV} ${WRKSRC}/doc/pdmenurc.man.done ${WRKSRC}/doc/pdmenurc.man

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ANNOUNCE BUGS TODO \
		${DESTDIR}${PREFIX}/share/doc/pdmenu
	cd ${WRKSRC}/examples && ${INSTALL_DATA} README ba.lpd pdmenurc \
		pdmenurc.complex pdmenurc.monitor showdir.pl \
		${DESTDIR}${PREFIX}/share/examples/pdmenu
	cd ${WRKSRC}/examples/newbie && ${INSTALL_DATA} modem-check \
		pdmenurc.newbie	rpm-info-on-command \
		${DESTDIR}${PREFIX}/share/examples/pdmenu/newbie

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
