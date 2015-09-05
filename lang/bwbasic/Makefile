# $NetBSD: Makefile,v 1.18 2015/09/05 23:56:56 wiedi Exp $

DISTNAME=	bwbasic-3.00
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bwbasic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jspath@bcpl.net
HOMEPAGE=	http://sourceforge.net/projects/bwbasic/
COMMENT=	The Bywater Basic interpreter
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99

SHARE_DIR=	${PREFIX}/share/bwbasic

CFLAGS+=		-DHAVE_ISNAN=1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${SHARE_DIR}

post-install:
	${CP} -r ${WRKSRC}/bwbtest ${DESTDIR}${SHARE_DIR}
	${FIND} ${DESTDIR}${SHARE_DIR} -type d -print | ${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${DESTDIR}${SHARE_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_MAN} ${WRKSRC}/bwbasic.doc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
