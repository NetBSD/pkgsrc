# $NetBSD: Makefile,v 1.26 2012/10/02 20:11:37 asau Exp $

DISTNAME=		cim-3.30
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		libtool_path=${PKG_LIBTOOL:Q}
USE_TOOLS+=		perl:run
USE_LIBTOOL=		YES
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
