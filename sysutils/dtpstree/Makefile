# $NetBSD: Makefile,v 1.6 2017/07/08 12:06:56 kamil Exp $
#

DISTNAME=	dtpstree-1.0.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://code.douglasthrift.net/files/dtpstree/
MASTER_SITES+=	http://apt.douglasthrift.net/files/dtpstree/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	douglas@douglasthrift.net
HOMEPAGE=	http://code.douglasthrift.net/trac/dtpstree
COMMENT=	Display a tree of processes
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash aclocal autoconf automake
MAKE_FILE=	GNUmakefile

REPLACE_BASH+=	autogen.sh

.include "options.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
