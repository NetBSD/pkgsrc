# $NetBSD: sid-filter.m4,v 1.1.1.1 2010/03/12 22:42:55 pettai Exp $

include(confBUILDTOOLSDIR`/M4/switch.m4')

define(`confMT', `TRUE')
define(`confREQUIRE_LIBSM', `true')

dnl Sometimes enabling this next line clears up some load-time warnings
dnl APPENDDEF(`confLIBS', `-lcipher ')

bldPUSH_SMLIB(`sm')
bldPUSH_SMLIB(`marid')

PREPENDDEF(`confINCDIRS', `-I../../sendmail ')
PREPENDDEF(`confINCDIRS', `-I../../libmarid ')

dnl Disable these three lines if you want to use the OS-provided resolver
dnl instead of the provided asynchronous resolver library.
bldPUSH_SMLIB(`ar')
PREPENDDEF(`confINCDIRS', `-I../../libar ')
APPENDDEF(`confENVDEF', `-DUSE_ARLIB ')

dnl Enable these next line if needed to specify the locations of libmilter.a
dnl and the libmilter include files:
APPENDDEF(`confINCDIRS', `-I@LMBASE@/include')
APPENDDEF(`confLIBDIRS', `-L@LMBASE@/lib')


bldPRODUCT_START(`executable', `sid-filter')
define(`bldSOURCES', `sid-filter.c rfc2822.c util.c ')
PREPENDDEF(`confLIBS', `-lmilter -lpthread')
bldPRODUCT_END

bldPRODUCT_START(`manpage', `sid-filter')
define(`bldSOURCES', `sid-filter.8')
bldPRODUCT_END

bldFINISH
