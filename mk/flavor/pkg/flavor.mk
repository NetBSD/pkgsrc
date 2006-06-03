# $NetBSD: flavor.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $
#
# This Makefile fragment provides variable and target overrides that are
# specific to the pkgsrc native package format.
#

# PKG_FILELIST_CMD outputs the list of files owned by ${PKGNAME} as
# registered on the system.
#
PKG_FILELIST_CMD=	${PKG_INFO} -qL ${PKGNAME:Q}

.include "${PKGSRCDIR}/mk/flavor/pkg/depends.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/check.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/metadata.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/install.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/deinstall.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/replace.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/package.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/views.mk"

.include "${PKGSRCDIR}/mk/flavor/pkg/utility.mk"
