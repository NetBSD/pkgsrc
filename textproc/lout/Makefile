# $NetBSD: Makefile,v 1.22 2022/11/12 09:10:24 nikita Exp $

DISTNAME=	lout-3.40
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://download.savannah.gnu.org/releases/lout/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/lout
COMMENT=	Basser Lout, a TeX/troff-like formatter with PostScript/PDF output
LICENSE=	gnu-gpl-v3

MAKE_FILE=		makefile
NO_CONFIGURE=		yes
INSTALL_TARGET=		allinstall
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
