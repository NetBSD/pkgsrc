# $NetBSD: Makefile,v 1.19 2017/01/19 06:48:46 wen Exp $

DISTNAME=	bwbasic-3.10
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

CFLAGS+=		-DHAVE_ISNAN=1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/bwbasic.doc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
