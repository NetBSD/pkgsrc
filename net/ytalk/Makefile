# $NetBSD: Makefile,v 1.24 2019/11/03 11:45:59 rillig Exp $

DISTNAME=	ytalk-3.3.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ourproject.org/pub/ytalk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ytalk.ourproject.org/
COMMENT=	Multi-user replacement for UNIX talk

CONFLICTS+=	ytalk-x11-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
