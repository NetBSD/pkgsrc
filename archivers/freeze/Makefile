# $NetBSD: Makefile,v 1.27 2018/07/04 13:40:07 jperkin Exp $

DISTNAME=	freeze-2.5
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/compression/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FREEZE / MELT compression program - often used in QNX

CONFLICTS=	statist-[0-9]* # bin/statist

GNU_CONFIGURE=	yes
BUILD_TARGET=	prog

# Allow "melting" freeze-1.0-format archives.
CFLAGS+=	-DCOMPAT=1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		freeze
SUBST_STAGE.freeze=	pre-configure
SUBST_FILES.freeze=	*.1
SUBST_SED.freeze=	-e 's|@PREFIX@|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
