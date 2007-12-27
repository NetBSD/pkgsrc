# $NetBSD: Makefile,v 1.11 2007/12/27 12:08:01 obache Exp $
#

DISTNAME=		srsh-1.2
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Emulate rsh client behavior using ssh

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	post-extract
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,/man/,/${PKGMANDIR}/,'

.include "../../mk/bsd.pkg.mk"
