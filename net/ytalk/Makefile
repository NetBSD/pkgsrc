# $NetBSD: Makefile,v 1.8 2002/12/22 19:39:26 jmmv Exp $

DISTNAME=       ytalk-3.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=system/network/chat/}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.iagora.com/~espel/ytalk/ytalk.html
COMMENT=	Multi-user replacement for UNIX talk

GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
