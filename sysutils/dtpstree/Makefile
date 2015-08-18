# $NetBSD: Makefile,v 1.4 2015/08/18 07:31:17 wiz Exp $
#

DISTNAME=	dtpstree-1.0.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://code.douglasthrift.net/files/dtpstree/ \
		http://apt.douglasthrift.net/files/dtpstree/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	douglas@douglasthrift.net
HOMEPAGE=	http://code.douglasthrift.net/trac/dtpstree
COMMENT=	Display a tree of processes
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
