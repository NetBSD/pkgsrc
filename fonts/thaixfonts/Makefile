# $NetBSD: Makefile,v 1.4 2008/05/11 05:41:58 obache Exp $
#

DISTNAME=	thaixfonts-1.1-3.noarch
PKGNAME=	thaixfonts-1.1.3
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.fedu.uec.ac.jp/ZzzThai/linux/redhat/RPMS/noarch/
EXTRACT_SUFX=	.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fedu.uec.ac.jp/ZzzThai/fonts.html
COMMENT=	Various X11 Thai fonts in tis-620 encoding

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes

MAKE_ENV+=	FONTDIR=${FONTDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/thaixfonts/
INSTALLATION_DIRS=	${FONTDIR}

WRKSRC=		${WRKDIR}/usr/share/fonts/TIS-620/misc/

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-extract:
	cd ${WRKDIR} && rpm2cpio ${_DISTDIR}/${DISTFILES} | \
		cpio -i --make-directories \*

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.gz fonts.* ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
