# $NetBSD: Makefile,v 1.1.1.1 2007/11/03 15:33:12 rillig Exp $
#

DISTNAME=	thaixfonts-1.1-3.noarch
PKGNAME=	thaixfonts-1.1.3
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.fedu.uec.ac.jp/ZzzThai/linux/redhat/RPMS/noarch/
EXTRACT_SUFX=	.rpm

MAINTAINER=	scole_mail@softhome.net
HOMEPAGE=	http://www.fedu.uec.ac.jp/ZzzThai/fonts.html
COMMENT=	Various X11 Thai fonts in tis-620 encoding

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm

USE_X11BASE=	yes

MAKE_ENV+=	FONTDIR=${FONTDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/thaixfonts/

WRKSRC=		${WRKDIR}/usr/share/fonts/TIS-620/misc/

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-extract:
	cd ${WRKDIR} && rpm2cpio ${_DISTDIR}/${DISTFILES} | \
		cpio -i --make-directories \*

pre-install:
	${INSTALL_DATA_DIR} ${FONTDIR}

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.gz fonts.* ${FONTDIR}

.include "../../mk/bsd.pkg.mk"
