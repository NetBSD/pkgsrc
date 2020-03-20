# $NetBSD: Makefile,v 1.8 2020/03/20 11:57:38 nia Exp $
#

DISTNAME=	LinLibertineTTF_5.1.3_2011_06_21
PKGNAME=	${DISTNAME:S/LinLibertineTTF_/linux-libertine-ttf-/:C/_[^_].*$//}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxlibertine/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxlibertine.sourceforge.net/
COMMENT=	Free TrueType font family
LICENSE=	gnu-gpl-v2 OR ofl-v1.0

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
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
