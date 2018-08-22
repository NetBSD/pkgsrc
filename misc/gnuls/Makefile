# $NetBSD: Makefile,v 1.28 2018/08/22 09:45:43 wiz Exp $
#

PKGREVISION= 1
.include "../../sysutils/coreutils/Makefile.common"

PKGNAME=	${DISTNAME:S/coreutils/gnuls/}
CATEGORIES=	misc

COMMENT=	GNU ls utility with color support

CONFLICTS=	coreutils-[0-9]* linuxls-[0-9]*

BUILD_TARGET=	gnuls

AUTO_MKDIRS=	yes

do-install:
.for f in ls dircolors
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} \
		${DESTDIR}${PREFIX}/bin/g${f}
	${INSTALL_DATA} ${WRKSRC}/man/${f}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/g${f}.1
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
