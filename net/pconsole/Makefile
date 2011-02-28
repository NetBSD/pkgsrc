# $NetBSD: Makefile,v 1.7 2011/02/28 14:52:59 wiz Exp $
#

DISTNAME=	pconsole-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ka.sara.nl/home/walter/pconsole/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ka.sara.nl/home/walter/pconsole/
COMMENT=	Parallel console tool to access several host via one input tty

PKG_DESTDIR_SUPPORT=	user-destdir

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
