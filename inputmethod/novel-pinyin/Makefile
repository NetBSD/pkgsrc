# $NetBSD: Makefile,v 1.1.1.1 2009/11/24 12:13:02 obache Exp $
#

DISTNAME=	novel-pinyin-0.2.5
CATEGORIES=	inputmethod
MASTER_SITES=	http://downloads.sourceforge.net/project/novel-pinyin/novel-pinyin/0.2.5/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://novel-pinyin.sourceforge.net/
COMMENT=	HMM-based sentence pinyin input method for Chinese
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool pkg-config

USE_SCIM_GTKUTILS=	yes

.include "../../databases/db4/buildlink3.mk"
BUILDLINK_TRANSFORM+=	l:db:db4
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
