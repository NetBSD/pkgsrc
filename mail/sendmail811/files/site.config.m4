# $NetBSD: site.config.m4,v 1.1.1.1 2002/09/23 12:38:45 markd Exp $

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
