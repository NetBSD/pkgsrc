# $NetBSD: Makefile,v 1.10 2004/01/20 12:19:16 agc Exp $
#

DISTNAME=	maude-src
PKGNAME=	maude-2.0.1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		fm.maude

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming

.if !exists(/usr/bin/flex)
BUILD_DEPENDS+=	flex-[0-9]*:../../devel/flex
.endif
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/Maude-${PKGVERSION}
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/maude

post-install:
	${INSTALL_DATA} ${DISTDIR}/fm.maude ${PREFIX}/share/maude
.include "../../devel/buddy/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/libtecla/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
