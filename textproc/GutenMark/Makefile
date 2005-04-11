# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:31 tv Exp $
#

DISTNAME=	GutenMark_source_${GVER}
PKGNAME=	GutenMark-${GVER}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sandroid.org/GutenMark/SoftwareSnapshots/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.sandroid.org/GutenMark/
COMMENT=	Automatic, high-quality Gutenberg text formatter to LaTeX or HTML

DEPENDS+=	GutenMark-words-[0-9]*:../../textproc/GutenMark-words

WRKSRC=		${WRKDIR}/GutenMark-source
GVER=		20020714
USE_GNU_TOOLS+=	make
BUILD_TARGET=	GutenMark

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GutenMark ${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
