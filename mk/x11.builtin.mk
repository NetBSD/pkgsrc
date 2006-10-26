# $NetBSD: x11.builtin.mk,v 1.2 2006/10/26 17:08:08 rillig Exp $
#
# x11.builtin.mk will include the builtin.mk file from the appropriate
# X11 distribution.
#

.include "../../mk/x11.version.mk"
.include "${X11_PKGSRCDIR.${X11_TYPE}}/builtin.mk"
