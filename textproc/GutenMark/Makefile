# $NetBSD: Makefile,v 1.1.1.1 2002/12/05 15:02:24 wiz Exp $
#

DISTNAME=	GutenMark_source_${GVER}
PKGNAME=	GutenMark-${GVER}
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sandroid.org/GutenMark/SoftwareSnapshots/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.sandroid.org/GutenMark/
COMMENT=	automatic, high-quality Gutenberg text formatter to LaTeX or HTML

DEPENDS+=	GutenMark-words-[0-9]*:../../textproc/GutenMark-words

GVER=		20020714
WRKSRC=		${WRKDIR}/GutenMark-source
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
ALL_TARGET=	GutenMark

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GutenMark ${PREFIX}/bin

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
