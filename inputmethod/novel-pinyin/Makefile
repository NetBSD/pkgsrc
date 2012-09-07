# $NetBSD: Makefile,v 1.15 2012/09/07 19:16:57 adam Exp $

DISTNAME=	novel-pinyin-0.2.5
PKGREVISION=	13
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novel-pinyin/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://novel-pinyin.sourceforge.net/
COMMENT=	HMM-based sentence pinyin input method for Chinese
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool pkg-config msgfmt msgmerge xgettext
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
