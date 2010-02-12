# $NetBSD: Makefile,v 1.21 2010/02/12 14:42:45 joerg Exp $
#

DISTNAME=	depot-5.14
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	pkgsrc-users@NetBSD.org
# "Most of the content here is being removed and archived."
# HOMEPAGE=	http://asg.web.cmu.edu/depot/
COMMENT=	Maps several separate packages into a tree without merging them

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	lex yacc

CONFIGURE_ENV+=	INSTALL="" CC=${CC:Q}
MAKE_ENV+=	CC=${CC:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

INSTALL_DIRS=	src/cmd man/man1 man/man5
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
