# $NetBSD: Makefile,v 1.4 2012/10/03 18:28:27 asau Exp $
#

DISTNAME=	LinLibertineTTF_5.1.3_2011_06_21
PKGNAME=	${DISTNAME:S/LinLibertineTTF_/linux-libertine-ttf-/:C/_[^_].*$//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxlibertine/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxlibertine.sourceforge.net/
COMMENT=	Free TrueType font family
#LICENSE=	gnu-gpl-v2 OR SIL OPEN FONT LICENSE Version 1.0

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/linux-libertine-ttf
FONTS_DIRS.ttf=	${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/GPL.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/OFL.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
