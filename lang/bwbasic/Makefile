# $NetBSD: Makefile,v 1.14 2010/03/03 12:38:28 obache Exp $

PKGNAME=	${DISTNAME:=pl2}
DISTNAME=	bwbasic-2.20
CATEGORIES=	lang
MASTER_SITES=	http://www.nicholson.com/rhn/files/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jspath@bcpl.net
HOMEPAGE=	http://bwbasic.sourceforge.net/
COMMENT=	The Bywater Basic interpreter
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/bwbasic-2.20p2
BWBASIC_WRKSRC=	${WRKSRC}/bwbasic-2.20
DIST_SUBDIR=	${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	${BWBASIC_WRKSRC}
BUILD_DIRS=	${CONFIGURE_DIRS}

SHARE_DIR=	${PREFIX}/share/bwbasic

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${SHARE_DIR}

pre-patch:
	${CP} ${WRKSRC}/bwb-2.20-patch01/* ${BWBASIC_WRKSRC}
	${CP} ${WRKSRC}/bwb-2.20-patch02/* ${BWBASIC_WRKSRC}

post-install:
	${CP} -r ${BWBASIC_WRKSRC}/bwbtest ${DESTDIR}${SHARE_DIR}
	${FIND} ${DESTDIR}${SHARE_DIR} -type d -print | ${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${DESTDIR}${SHARE_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_MAN} ${BWBASIC_WRKSRC}/bwbasic.doc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
