# $NetBSD: Makefile,v 1.20 2010/02/11 23:06:39 joerg Exp $
#

DISTNAME=	ttt-1.8.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.sonycsl.co.jp/pub/kjc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sonycsl.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=	install install-man
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			exec_prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56]*)
.include "../../mk/pthread.buildlink3.mk"
.endif
.endif

.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
