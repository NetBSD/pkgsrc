# $NetBSD: Makefile,v 1.10 2004/02/28 12:21:48 grant Exp $

DISTNAME=       ytalk-3.1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=system/network/chat/}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.iagora.com/~espel/ytalk/ytalk.html
COMMENT=	Multi-user replacement for UNIX talk

GNU_CONFIGURE=	yes
USE_PKGINSTALL=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if defined(YTALK_USE_X11) && empty(YTALK_USE_X11:M[Nn][Oo])
CONFIGURE_ARGS+=	--with-x
USE_X11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/bsd.pkg.mk"
