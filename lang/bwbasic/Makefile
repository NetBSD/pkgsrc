# $NetBSD: Makefile,v 1.15 2012/01/15 15:29:31 ryoon Exp $

DISTNAME=	bwbasic-2.50
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bwbasic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jspath@bcpl.net
HOMEPAGE=	http://sourceforge.net/projects/bwbasic/
COMMENT=	The Bywater Basic interpreter
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes

SHARE_DIR=	${PREFIX}/share/bwbasic

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${SHARE_DIR}

post-install:
	${CP} -r ${WRKSRC}/bwbtest ${DESTDIR}${SHARE_DIR}
	${FIND} ${DESTDIR}${SHARE_DIR} -type d -print | ${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${DESTDIR}${SHARE_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_MAN} ${WRKSRC}/bwbasic.doc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
