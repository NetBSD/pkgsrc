# $NetBSD: Makefile,v 1.18 2011/07/14 00:40:13 jklos Exp $

DISTNAME=	ytalk-3.3.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iagora.com/~espel/ytalk/ytalk.html
COMMENT=	Multi-user replacement for UNIX talk

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	ytalk-x11-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/ytalk
CONF_FILES=	${EGDIR}/ytalkrc ${PKG_SYSCONFDIR}/ytalkrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
