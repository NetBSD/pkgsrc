# $NetBSD: Makefile,v 1.26 2022/12/28 12:20:20 wiz Exp $

DISTNAME=		mined-2022.27
CATEGORIES=		editors
MASTER_SITES=		http://towo.net/mined/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} UCD.zip Unihan.zip BIG5.TXT
SITES.UCD.zip=		http://www.unicode.org/Public/UNIDATA/
SITES.Unihan.zip=	http://www.unicode.org/Public/UNIDATA/
SITES.BIG5.TXT=		http://www.unicode.org/Public/MAPPINGS/OBSOLETE/EASTASIA/OTHER/
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mined.github.io/
COMMENT=	Unicode text editor
LICENSE=	gnu-gpl-v3

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
MAKE_FLAGS+=	OPT=${CFLAGS:Q}
MAKE_FLAGS+=	root=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}

post-extract:
.for f in UCD.zip Unihan.zip BIG5.TXT
	${CP} ${_DISTDIR}/${f} ${WRKSRC}/src
.endfor

post-install:
	${MV} ${DESTDIR}${DESTDIR}/usr/share ${DESTDIR}${PREFIX}/share
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
