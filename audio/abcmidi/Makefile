# $NetBSD: Makefile,v 1.15 2013/03/03 10:19:10 shattered Exp $
#

DISTNAME=	abcMIDI-${ABCMIDIVER}
PKGNAME=	abcmidi-${ABCMIDIVER:S/-//g}
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.ca/~seymour/runabc/ \
		http://ifdo.pugmarks.com/~seymour/backup/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://abc.sourceforge.net/abcMIDI/
COMMENT=	Music utilities for abc
LICENSE=	gnu-gpl-v2

ABCMIDIVER=	2012-12-01

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
