# $NetBSD: Makefile,v 1.8 2012/10/23 17:18:56 asau Exp $
#

DISTNAME=	pconsole-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ka.sara.nl/home/walter/pconsole/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ka.sara.nl/home/walter/pconsole/
COMMENT=	Parallel console tool to access several host via one input tty

GNU_CONFIGURE=	yes

USE_TOOLS+=	ksh:run

REPLACE_KSH=	pconsole.sh.in

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pconsole.sh.in
SUBST_VARS.path=	PREFIX X11PREFIX

INSTALLATION_DIRS=	share/doc/pconsole
INSTALL_MAKE_FLAGS=	bindir=${DESTDIR}${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.pconsole ${DESTDIR}${PREFIX}/share/doc/pconsole

.include "../../mk/bsd.pkg.mk"
