# $NetBSD: Makefile,v 1.1.1.1 2010/08/15 09:07:11 obache Exp $
#

DISTNAME=	dtpstree-1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://code.douglasthrift.net/files/dtpstree/ \
		http://apt.douglasthrift.net/files/dtpstree/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	douglas@douglasthrift.net
HOMEPAGE=	http://code.douglasthrift.net/trac/dtpstree
COMMENT=	Display a tree of processes
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
