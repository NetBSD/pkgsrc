# $NetBSD: Makefile,v 1.22 2006/07/17 17:17:43 joerg Exp $

DISTNAME=	freeze-2.5
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/compression/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FREEZE / MELT compression program - often used in QNX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
BUILD_TARGET=	prog

# Allow "melting" freeze-1.0-format archives.
CFLAGS+=	-DCOMPAT=1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		freeze
SUBST_STAGE.freeze=	post-patch
SUBST_FILES.freeze=	*.1
SUBST_SED.freeze=	-e 's|@PREFIX@|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
