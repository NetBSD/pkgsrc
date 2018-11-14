# $NetBSD: Makefile,v 1.142 2018/11/14 17:14:52 kleink Exp $

.include "../../graphics/cairo/Makefile.common"

TEST_TARGET=			check

.include "options.mk"

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2.95
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.9
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# include?
#.include "../../print/libspectre/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.30.0
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
