# $NetBSD: Makefile,v 1.48 2024/05/22 09:46:12 bouyer Exp $

DISTNAME=	mirror-2.9
PKGREVISION=	15
CATEGORIES=	net
MASTER_SITES=	# ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sunsite.org.uk/packages/mirror/
COMMENT=	Mirror packages on remote sites
LICENSE=	mit

WRKSRC=		${WRKDIR}
MAKE_FILE=	makefile
MAKE_FLAGS+=	GRP=${BINGRP}

USE_TOOLS+=	perl:run
REPLACE_PERL=	do_unlinks.pl mirror.pl mm.pl pkgs_to_mmin.pl

CONF_FILES+=	${PREFIX}/lib/mirror/mirror.defaults.dist \
		${PREFIX}/lib/mirror/mirror.defaults

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e 's:!!PREFIX!!:${PREFIX}:g'
SUBST_FILES.prefix=	mirror.pl mm.pl
SUBST_MESSAGE.prefix=	Fixing hardcoded installation prefix.
SUBST_STAGE.prefix=	pre-configure

INSTALLATION_DIRS+=	bin lib/mirror ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
