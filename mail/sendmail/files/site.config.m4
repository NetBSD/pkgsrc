# $NetBSD: site.config.m4,v 1.2 2002/06/23 11:46:04 tron Exp $

# pathnames specific to pkgsrc
#
define(`confEBINDIR', `${PREFIX}/libexec/sendmail')
define(`confMBINDIR', `${PREFIX}/libexec/sendmail')
define(`confSBINDIR', `${PREFIX}/sbin')
define(`confUBINDIR', `${PREFIX}/bin')
define(`confHFDIR', `${PREFIX}/share/misc')
define(`confMANROOT', `${PREFIX}/man/cat')
APPENDDEF(`confENVDEF', `-I${BUILDLINK_DIR}/include')
APPENDDEF(`confLIBS', `-L${BUILDLINK_DIR}/lib')
