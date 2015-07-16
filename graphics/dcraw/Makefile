# $NetBSD: Makefile,v 1.43 2015/07/16 16:46:47 adam Exp $
#
# Changes can be found in the RCS file at
# http://www.cybercom.net/~dcoffin/dcraw/RCS/dcraw.c,v

DISTNAME=	dcraw-9.26.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	Raw digital camera decoder

WRKSRC=			${WRKDIR}/${PKGBASE}

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

LIBS+=		-lm -ljasper -ljpeg
CFLAGS+=	-DLOCALEDIR=\"${PREFIX}/${PKGLOCALEDIR}/locale\"

DCRAW_LOCALES=		ca cs da de eo es fr hu it ja nl pl pt ro ru sv zh_CN zh_TW

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
.for lang in ${DCRAW_LOCALES}
INSTALLATION_DIRS+=	${PKGMANDIR}/${lang}/man1
.endfor
.for lang in ${DCRAW_LOCALES}
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/${lang}/LC_MESSAGES
.endfor

BROKEN_GETTEXT_DETECTION=	yes

.include "options.mk"

do-build:
	set -e; cd ${WRKSRC};					\
	${CC} ${CFLAGS} dcraw.c -o dcraw ${LDFLAGS} ${LIBS};	\
	for l in ${DCRAW_LOCALES}; do				\
		msgfmt -o dcraw_$${l}.mo dcraw_$${l}.po;	\
	done;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dcraw.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for l in ${DCRAW_LOCALES}
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
