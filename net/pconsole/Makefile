# $NetBSD: Makefile,v 1.10 2015/07/04 16:18:38 joerg Exp $
#

DISTNAME=	pconsole-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.heiho.net/pconsole/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.heiho.net/pconsole/
COMMENT=	Parallel console tool to access several host via one input tty
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=	ksh:run

REPLACE_KSH=	pconsole.sh.in

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pconsole.sh.in
SUBST_VARS.path=	PREFIX X11BASE

INSTALLATION_DIRS=	share/doc/pconsole
INSTALL_MAKE_FLAGS=	bindir=${DESTDIR}${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.pconsole ${DESTDIR}${PREFIX}/share/doc/pconsole

.include "../../mk/bsd.pkg.mk"
