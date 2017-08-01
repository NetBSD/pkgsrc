# $NetBSD: Makefile,v 1.20 2017/08/01 14:59:00 wiz Exp $

DISTNAME=	bwbasic-3.10
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bwbasic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jspath@bcpl.net
HOMEPAGE=	https://sourceforge.net/projects/bwbasic/
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
