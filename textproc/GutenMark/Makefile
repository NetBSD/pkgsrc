# $NetBSD: Makefile,v 1.17 2012/10/25 06:55:38 asau Exp $
#

DISTNAME=	GutenMark_source_dev-${GVER}
PKGNAME=	GutenMark-${GVER}
CATEGORIES=	textproc
MASTER_SITES=	http://www.sandroid.org/GutenMark/wasftp.GutenMark/SoftwareSnapshots/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sandroid.org/GutenMark/
COMMENT=	Automatic, high-quality Gutenberg text formatter to LaTeX or HTML

DEPENDS+=	GutenMark-words-[0-9]*:../../textproc/GutenMark-words

WRKSRC=		${WRKDIR}/GutenMark-source
GVER=		20090510
USE_TOOLS+=	gmake
BUILD_TARGET=	GutenMark

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GutenMark ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
