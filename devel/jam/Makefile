# $NetBSD: Makefile,v 1.21 2026/02/10 20:17:59 jakllsch Exp $
#

DISTNAME=	ft${PKGNAME_NOREV}
PKGNAME=	jam-2.5.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}
#MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freetype.sourceforge.net/jam/index.html
#HOMEPAGE=	https://www.perforce.com/jam/jam.html
COMMENT=	Program construction tool, like make(1)

CONFLICTS=	acunia-jam-[0-9]*

GNU_CONFIGURE=	yes

USE_TOOLS+=	yacc gmake
MAKEFLAGS+=	LINKFLAGS=${LDFLAGS:M*:Q}
AUTO_MKDIRS=	yes

do-install:
	cd ${WRKSRC}/bin.* \
	&& ${INSTALL_PROGRAM} jam mkjambase ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} Porting README RELNOTES *.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
