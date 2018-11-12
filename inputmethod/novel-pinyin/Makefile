# $NetBSD: Makefile,v 1.36 2018/11/12 03:52:23 ryoon Exp $

DISTNAME=	novel-pinyin-0.2.5
PKGREVISION=	31
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novel-pinyin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://novel-pinyin.sourceforge.net/
COMMENT=	HMM-based sentence pinyin input method for Chinese
LICENSE=	gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++03
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
