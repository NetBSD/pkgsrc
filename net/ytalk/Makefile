# $NetBSD: Makefile,v 1.22 2017/09/06 09:03:03 wiz Exp $

DISTNAME=	ytalk-3.3.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/pkgsrc/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.iagora.com/~espel/ytalk/ytalk.html
COMMENT=	Multi-user replacement for UNIX talk

CONFLICTS+=	ytalk-x11-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
