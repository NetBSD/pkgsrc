# $NetBSD: Makefile,v 1.24 2021/10/17 08:58:17 nia Exp $
#

DISTNAME=	abcMIDI-2021.10.15
PKGNAME=	${DISTNAME:tl:S/.//g}
CATEGORIES=	audio
MASTER_SITES=	https://ifdo.ca/~seymour/runabc/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ifdo.ca/~seymour/runabc/top.html
COMMENT=	Command line utilities for working with abc music notation files
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	share/doc/${PKGBASE}/programming \
			share/examples/${PKGBASE}

WRKSRC=		${WRKDIR}/abcmidi
GNU_CONFIGURE=	yes

post-install:
	cd ${WRKSRC}/doc/programming && ${INSTALL_DATA} abc2midi.txt \
		coding.txt midi2abc.txt split.abc yaps.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/programming
	cd ${WRKSRC}/samples && ${INSTALL_DATA} araber.abc baym_rebin.abc \
		boys.abc coleraine.abc daramud.abc demo.abc dergasn.abc \
		drums.abc \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
