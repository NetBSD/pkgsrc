# $NetBSD: Makefile,v 1.39 2013/11/03 16:02:26 wiz Exp $

DISTNAME=	dcraw-9.19
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	Raw digital camera decoder

USE_PKGLOCALEDIR=	yes
WRKSRC=			${WRKDIR}/${PKGBASE}
USE_TOOLS+=		msgfmt
USE_LANGUAGES=		c

LIBS+=		-lm -ljasper -ljpeg
CFLAGS+=	-DLOCALEDIR=\"${PREFIX}/${PKGLOCALEDIR}/locale\"

DCRAW_MANS=		ca cs da de eo es fr hu it pl pt ru sv zh_CN zh_TW
DCRAW_LOCALES=		ca cs da de eo es fr hu it nl pl pt ru sv zh_CN zh_TW

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
.for lang in ${DCRAW_MANS}
INSTALLATION_DIRS+=	${PKGMANDIR}/${lang}/man1
.endfor
.for lang in ${DCRAW_LOCALES}
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/${lang}/LC_MESSAGES
.endfor

BROKEN_GETTEXT_DETECTION=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcraw
PKG_SUPPORTED_OPTIONS=	lcms
PKG_SUGGESTED_OPTIONS=	lcms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlcms)
LIBS+=		-llcms
.include "../../graphics/lcms/buildlink3.mk"
.else
CFLAGS+=	-DNO_LCMS
.endif

do-build:
	set -e; cd ${WRKSRC};						\
	env ${MAKE_ENV} ${CC} ${CFLAGS} dcraw.c -o dcraw ${LDFLAGS} ${LIBS}; \
	for l in ${DCRAW_LOCALES}; do					\
		env ${MAKE_ENV} msgfmt -o dcraw_$${l}.mo dcraw_$${l}.po; \
	done;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dcraw.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for l in ${DCRAW_MANS}
	${INSTALL_MAN} ${WRKSRC}/dcraw_${l}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/${l}/man1/dcraw.1
.endfor
.for l in ${DCRAW_LOCALES}
	${INSTALL_DATA} ${WRKSRC}/dcraw_${l}.mo \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/${l}/LC_MESSAGES/dcraw.mo
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
