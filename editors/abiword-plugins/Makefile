# $NetBSD: Makefile,v 1.47 2012/09/15 10:04:24 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../editors/abiword/Makefile.common"

PKGNAME=	abiword-plugins-${ABIVERSION}
PKGREVISION=	10
COMMENT=	Plugins enhancing Abiword's capabilities

CONFIGURE_ARGS+= --without-gnomevfs

BUILD_DEPENDS+=	abiword-${ABIVERSION}{,nb*}:../../editors/abiword

.include "../../mk/bsd.prefs.mk"

# disabled plugins:
#  aiksaurus mathview ots gda goffice grammar psiconv rsvg wordperfect wpg
CONFIGURE_ARGS+=	--enable-plugins="applix babelfish bmp clarisworks collab command docbook eml freetranslation garble gdict gimp google hancom hrtext iscii kword latex loadbindings mht mif mswrite opendocument openwriter openxml opml paint passepartout pdb pdf presentation s5 sdw t602 urldict wikipedia wmf wml xslfo"

BUILD_DIRS=	plugins

#.include "../../converters/libwpd/buildlink3.mk"
#.include "../../converters/libwpg/buildlink3.mk"
#.include "../../converters/libwps/buildlink3.mk"
#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../textproc/aiksaurus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
#.include "../../textproc/link-grammar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
