# $NetBSD: Makefile,v 1.24 2012/09/08 22:46:44 cheusov Exp $

DISTNAME=	freeze-2.5
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/compression/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FREEZE / MELT compression program - often used in QNX

CONFLICTS=	statist-[0-9]* # bin/statist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
