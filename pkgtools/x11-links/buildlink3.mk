# $NetBSD: buildlink3.mk,v 1.12 2008/01/05 16:22:15 tron Exp $
#
# Don't include this file manually!  It will be included as necessary
# by bsd.buildlink3.mk.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
X11_LINKS_BUILDLINK3_MK:=	${X11_LINKS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	x11-links
.endif

# x11-links must come first so that packages listed later can overwrite
# any symlinks created by buildlinking x11-links.
#
BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nx11-links}
BUILDLINK_PACKAGES:=	x11-links ${BUILDLINK_PACKAGES}
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}x11-links

.if !empty(X11_LINKS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.x11-links+=	x11-links>=0.35
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

.endif	# X11_LINKS_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
