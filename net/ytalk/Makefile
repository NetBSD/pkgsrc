# $NetBSD: Makefile,v 1.9 2003/01/28 22:03:58 jlam Exp $

DISTNAME=       ytalk-3.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=system/network/chat/}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.iagora.com/~espel/ytalk/ytalk.html
COMMENT=	Multi-user replacement for UNIX talk

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_PKGINSTALL=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/bsd.pkg.mk"
