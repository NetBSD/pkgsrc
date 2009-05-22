# $NetBSD: Makefile,v 1.5 2009/05/22 20:02:31 tnn Exp $
#

DISTNAME=	unfs3-0.9.22
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unfs3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unfs3.sourceforge.net/
COMMENT=	Userspace NFSv3 server

GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	gmake

CONF_FILES+=		${PREFIX}/share/examples/unfs3/exports \
			    ${PKG_SYSCONFDIR}/exports
RCD_SCRIPTS=		unfsd

INSTALLATION_DIRS+=	share/examples/unfs3

SUBST_CLASSES+=		exports
SUBST_STAGE.exports=	pre-configure
SUBST_MESSAGE.exports=	Fixing path to exports(5)
SUBST_FILES.exports=	daemon.c unfsd.8
SUBST_SED.exports=	-e 's,/etc/exports,${PKG_SYSCONFDIR}/exports,g'

.include "../../mk/bsd.prefs.mk"

post-install:
			${INSTALL_DATA} ${FILESDIR}/exports \
			    ${DESTDIR}${PREFIX}/share/examples/unfs3

.include "../../mk/bsd.pkg.mk"
