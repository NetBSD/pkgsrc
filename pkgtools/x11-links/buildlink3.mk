# $NetBSD: buildlink3.mk,v 1.27 2010/06/04 10:52:21 ghen Exp $
#
# Don't include this file manually!  It will be included as necessary
# by bsd.buildlink3.mk.

# x11-links is sorted first in mk/buildlink3/bsd.buildlink3.mk,
# so that symlinks created from it can be overriden by other packages.
#

BUILDLINK_TREE+=	x11-links

.if !defined(X11_LINKS_BUILDLINK3_MK)
X11_LINKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.x11-links+=	x11-links>=0.50
BUILDLINK_PKGSRCDIR.x11-links?=	../../pkgtools/x11-links
BUILDLINK_DEPMETHOD.x11-links?=	build

# Force all of the headers and libraries to be symlinked into
# ${BUILDLINK_X11_DIR}, even in the "pkgviews" case.
#
BUILDLINK_CONTENTS_FILTER.x11-links=					\
	${EGREP} '(include.*/|\.h$$|\.pc$$|/lib[^/]*$$)'

# Rename the symlinks so that they appear in ${BUILDLINK_X11_DIR}/include
# and ${BUILDLINK_X11_DIR}/lib.
#
BUILDLINK_FNAME_TRANSFORM.x11-links+=	-e "s|/share/x11-links/|/|"
.endif # X11_LINKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-x11-links
