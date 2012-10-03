# $NetBSD: Makefile,v 1.15 2012/10/03 18:28:26 asau Exp $
#

DISTNAME=	xfntmizi-1.1-2.noarch
PKGNAME=	ko-mizi-20010718
PKGREVISION=	1
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.mizi.co.kr/pub/hanIM/
EXTRACT_SUFX=	.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 fonts for KSC 5601 standard

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_X11BASE=		yes
USE_TOOLS+=		gzip gunzip

MAKE_ENV+=	FONTDIR=${FONTDIR:Q} GZIP_CMD=${GZIP_CMD:Q}

# fonts
MIZI_PCF=	mzgt16e.pcf mzgt16h1.pcf mzmj16h.pcf mzpg16h.pcf mzsm16h.pcf \
		mzgt16h.pcf mzmj16e.pcf mzpg16e.pcf mzsm16e.pcf

FONTDIR=	${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=	${FONTDIR}
INSTALLATION_DIRS+= ${FONTDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}
	(cd ${WRKSRC}; rpm2cpio ${_DISTDIR}/${DISTFILES} | \
	    cpio -i --make-directories *.pcf.Z)
	(cd ${WRKSRC}; for i in ${MIZI_PCF}; do \
		${GUNZIP_CMD} -c usr/lib/X11/fonts/misc/$$i.Z > $$i; \
	done)

do-configure:
	cd ${WRKSRC}; ${MAKE} prepare

.include "../../mk/bsd.pkg.mk"
