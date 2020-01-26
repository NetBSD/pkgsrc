# $NetBSD: Makefile,v 1.25 2020/01/26 17:31:58 rillig Exp $

DISTNAME=	ytalk-3.3.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ourproject.org/pub/ytalk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ytalk.ourproject.org/
COMMENT=	Multi-user replacement for UNIX talk

CONFLICTS+=	ytalk-x11-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
