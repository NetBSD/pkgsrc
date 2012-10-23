# $NetBSD: Makefile,v 1.19 2012/10/23 17:19:22 asau Exp $

DISTNAME=	ytalk-3.3.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iagora.com/~espel/ytalk/ytalk.html
COMMENT=	Multi-user replacement for UNIX talk

CONFLICTS+=	ytalk-x11-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
