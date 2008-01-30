# $NetBSD: Makefile,v 1.3 2008/01/30 09:39:13 tnn Exp $
#

DISTNAME=	unfs3-0.9.20
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unfs3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unfs3.sourceforge.net/
COMMENT=	Userspace NFSv3 server

GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

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

.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-lrpcsoc
CPPFLAGS+=		-Dxp_sock=xp_fd
.endif

post-install:
			${INSTALL_DATA} ${FILESDIR}/exports \
			    ${DESTDIR}${PREFIX}/share/examples/unfs3

.include "../../mk/bsd.pkg.mk"
