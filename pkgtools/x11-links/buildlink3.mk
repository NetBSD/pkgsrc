# $NetBSD: buildlink3.mk,v 1.81 2019/06/12 01:04:39 gutteridge Exp $
#
# Don't include this file manually!  It will be included as necessary
# by bsd.buildlink3.mk.
#
# x11-links is sorted first in mk/buildlink3/bsd.buildlink3.mk,
# so that symlinks created from it can be overriden by other packages.
#

BUILDLINK_TREE+=	x11-links

.if !defined(X11_LINKS_BUILDLINK3_MK)
X11_LINKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.x11-links+=	x11-links>=1.19
BUILDLINK_PKGSRCDIR.x11-links?=		../../pkgtools/x11-links
BUILDLINK_DEPMETHOD.x11-links?=		build

# Force all of the helper programs, headers and libraries to be symlinked
# into ${BUILDLINK_X11_DIR}.
#
BUILDLINK_CONTENTS_FILTER.x11-links=					\
	${EGREP} '(bin/.*|include.*/|\.h$$|\.pc$$|/lib[^/]*$$)'

# Rename the symlinks so that they appear in ${BUILDLINK_X11_DIR}/include
# and ${BUILDLINK_X11_DIR}/lib.
#
BUILDLINK_FNAME_TRANSFORM.x11-links+=	-e "s|/share/x11-links/|/|"
.endif # X11_LINKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-x11-links
