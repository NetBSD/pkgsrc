# $NetBSD: flavor.mk,v 1.2 2007/08/14 23:58:24 joerg Exp $
#
# This Makefile fragment provides variable and target overrides that are
# specific to the pkgsrc native package format.
#

# PKG_FILELIST_CMD outputs the list of files owned by ${PKGNAME} as
# registered on the system.
#
# For DESTDIR support, just use _DEPENDS_PLIST instead.
#
.if ${_USE_DESTDIR} == "no"
PKG_FILELIST_CMD=	${PKG_INFO} -qL ${PKGNAME:Q}
.else
PKG_FILELIST_CMD=	${SED} -e "/^@/d" -e "s|^|${PREFIX}/|" ${_DEPENDS_PLIST}
.endif

.include "${PKGSRCDIR}/mk/flavor/pkg/depends.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/check.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/metadata.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/install.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/deinstall.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/replace.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/package.mk"
.include "${PKGSRCDIR}/mk/flavor/pkg/views.mk"

.include "${PKGSRCDIR}/mk/flavor/pkg/utility.mk"
