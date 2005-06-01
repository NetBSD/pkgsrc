# $NetBSD: x11.builtin.mk,v 1.1 2005/06/01 18:03:06 jlam Exp $
#
# x11.builtin.mk will include the builtin.mk file from the appropriate
# X11 distribution.
#

.include "../../mk/x11.version.mk"
.sinclude "${X11_PKGSRCDIR.${X11_TYPE}}/builtin.mk"
