# $NetBSD: Makefile,v 1.18 2020/03/20 11:57:27 nia Exp $
#

DISTNAME=	ft${PKGNAME_NOREV}
PKGNAME=	jam-2.5.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}
#MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://freetype.sourceforge.net/jam/index.html
#HOMEPAGE=	http://www.perforce.com/jam/jam.html
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
