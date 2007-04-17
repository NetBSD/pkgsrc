# $NetBSD: site.config.m4,v 1.1.1.1 2007/04/17 10:16:53 jnemeth Exp $

# pathnames specific to pkgsrc
#
define(`confEBINDIR', `${PREFIX}/libexec/sendmail')
define(`confMBINDIR', `${PREFIX}/libexec/sendmail')
define(`confSBINDIR', `${PREFIX}/sbin')
define(`confUBINDIR', `${PREFIX}/bin')
define(`confHFDIR', `${PREFIX}/share/misc')
define(`confINSTALL_RAWMAN', 'yes')
define(`confDONT_INSTALL_CATMAN', 'yes')
define(`confMANROOT', `${PREFIX}/${PKGMANDIR}/man')
define(`confMANROOTMAN', `${PREFIX}/${PKGMANDIR}/man')
define(`confMAN1EXT', `1')
define(`confMAN3EXT', `3')
define(`confMAN4EXT', `4')
define(`confMAN5EXT', `5')
define(`confMAN8EXT', `8')
APPENDDEF(`confENVDEF', `-I${PREFIX}/include -DSMRSH_CMDDIR=\"${SMRSH_CMDDIR}\"')
APPENDDEF(`confLIBS', `-L${PREFIX}/lib')
APPENDDEF(`confMAPDEF', `-DSOCKETMAP')

# the following are handled by pkgsrc
define(`confINST_DEP',`')
define(`confNO_STATISTICS_INSTALL')
