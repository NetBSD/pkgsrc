# $NetBSD: Makefile,v 1.16 2012/10/30 13:24:31 drochner Exp $
#

DISTNAME=	tdb-1.2.10
CATEGORIES=	databases
MASTER_SITES=	http://www.samba.org/ftp/tdb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

# both install tdbtool and tdbdump
CONFLICTS+=	samba<3.6.6nb3

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-python
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE=	tdb.pc.in

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+= buildtools/bin/waf

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
