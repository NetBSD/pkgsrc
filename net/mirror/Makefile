# $NetBSD: Makefile,v 1.32 2007/03/01 19:33:39 wiz Exp $

DISTNAME=	mirror-2.9
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sunsite.org.uk/packages/mirror/
COMMENT=	Mirror packages on remote sites

WRKSRC=		${WRKDIR}
MAKE_FILE=	makefile
MAKE_FLAGS+=	GRP=${BINGRP}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

USE_TOOLS+=	perl:run
REPLACE_PERL=	do_unlinks.pl mirror.pl mm.pl pkgs_to_mmin.pl

CONF_FILES+=	${PREFIX}/lib/mirror/mirror.defaults.dist \
		${PREFIX}/lib/mirror/mirror.defaults

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e 's:!!PREFIX!!:${PREFIX}:g'
SUBST_FILES.prefix=	mirror.pl mm.pl
SUBST_MESSAGE.prefix=	Fixing hardcoded installation prefix.
SUBST_STAGE.prefix=	pre-configure

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mirror

.include "../../mk/bsd.pkg.mk"
