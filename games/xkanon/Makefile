# $NetBSD: Makefile,v 1.7 2023/01/29 21:16:24 ryoon Exp $
#

DISTNAME=	xkanon-gtk2-090830
PKGNAME=	xkanon-090830
PKGREVISION=	6
CATEGORIES=	games
#MASTER_SITES=	http://www.creator.club.ne.jp/~jagarl/
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
DISTFILES=	${DEFAULT_DISTFILES} xkanon-071209.tar.gz

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20100409004347/http://www.creator.club.ne.jp/~jagarl/xkanon.html
COMMENT=	Interpreter to execute AVG32 games for Microsoft Windows
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/xkanon-gtk
GNU_CONFIGURE=  yes
USE_LANGUAGES=	c c++03

USE_TOOLS+=	msgfmt pkg-config

post-extract:
	cp ${WRKDIR}/xkanon/ayusys.ja.po ${WRKDIR}/xkanon-gtk/ayusys_gtk2.ja.po

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-audiodev=/dev/audio
.endif

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=    gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
