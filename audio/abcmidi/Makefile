# $NetBSD: Makefile,v 1.19 2020/01/18 23:29:57 rillig Exp $
#

DISTNAME=	abcMIDI-${ABCMIDIVER}
PKGNAME=	abcmidi-${ABCMIDIVER:S/-//g}
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.ca/~seymour/runabc/
MASTER_SITES+=	http://ifdo.pugmarks.com/~seymour/backup/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://abc.sourceforge.net/abcMIDI/
COMMENT=	Music utilities for abc
LICENSE=	gnu-gpl-v2

ABCMIDIVER=	2014-12-25

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
