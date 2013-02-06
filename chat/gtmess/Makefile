# $NetBSD: Makefile,v 1.14 2013/02/06 23:21:47 jperkin Exp $
#

DISTNAME=		gtmess-0.91
PKGREVISION=		5
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtmess/}

MAINTAINER=		luapzz@gmail.com
HOMEPAGE=		http://gtmess.sourceforge.net/
COMMENT=		Console-based MSN Messenger client

DEPENDS+=		tk-[0-9]*:../../x11/tk

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		ac_cv_search_iconv=${BUILDLINK_LDADD.iconv:Q}
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

INCOMPAT_CURSES=	NetBSD-1.*-*

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
