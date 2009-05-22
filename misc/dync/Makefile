# $NetBSD: Makefile,v 1.16 2009/05/22 18:16:19 zafer Exp $
#

DISTNAME=		dync-1.1
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.westley.demon.co.uk/src/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.alistaircrooks.co.uk/software.html
COMMENT=		awk-like utility with C as language

GNU_CONFIGURE=		yes
BUILD_TARGET=		tst
USE_TOOLS+=		file_cmd
CONFIGURE_ENV+=		FILE_CMD=${TOOLS_FILE_CMD:Q}
CONFIGURE_ENV+=		ac_cv_path_LDCONFIG=${TOOLS_LDCONFIG:Q}

.include "../../mk/bsd.pkg.mk"
