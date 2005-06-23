# $NetBSD: Makefile,v 1.12 2005/06/23 17:07:47 kristerw Exp $
#

DISTNAME=		dync-1.1
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.alistaircrooks.co.uk/src/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.alistaircrooks.co.uk/software.html
COMMENT=		awk-like utility with C as language

GNU_CONFIGURE=		yes
BUILD_TARGET=		tst
USE_TOOLS+=		file_cmd
CONFIGURE_ENV+=		ac_cv_path_FILE_CMD="${TOOLS_FILE_CMD}"
CONFIGURE_ENV+=		ac_cv_path_LDCONFIG="${TOOLS_LDCONFIG}"

.include "../../mk/bsd.pkg.mk"
