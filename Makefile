# $NetBSD: Makefile,v 1.79 2007/01/06 17:10:42 rillig Exp $
#
# This is the top-level Makefile of pkgsrc. It contains a list of the
# categories of packages, as well as some targets that operate on the
# whole pkgsrc system.
#
# User-settable variables:
#
# SPECIFIC_PKGS
#	(See mk/defaults/mk.conf)
#
# SITE_SPECIFIC_PKGS
# HOST_SPECIFIC_PKGS
# GROUP_SPECIFIC_PKGS
# USER_SPECIFIC_PKGS
#	The specific packages that are to be built.
#
#	XXX: Why are there four distinct variables? The same could be
#	achieved using just SPECIFIC_PKGS as the list of packages and
#	leaving the remaining details to the user.
#
# See also:
#	mk/misc/toplevel.mk
#

.include "mk/bsd.prefs.mk"

.if defined(SPECIFIC_PKGS)
SUBDIR+=	${SITE_SPECIFIC_PKGS}
SUBDIR+=	${HOST_SPECIFIC_PKGS}
SUBDIR+=	${GROUP_SPECIFIC_PKGS}
SUBDIR+=	${USER_SPECIFIC_PKGS}
.else
SUBDIR+=	archivers
SUBDIR+=	audio
SUBDIR+=	benchmarks
SUBDIR+=	biology
SUBDIR+=	cad
SUBDIR+=	chat
SUBDIR+=	comms
SUBDIR+=	converters
SUBDIR+=	cross
SUBDIR+=	crosspkgtools
SUBDIR+=	databases
SUBDIR+=	devel
SUBDIR+=	editors
SUBDIR+=	emulators
SUBDIR+=	finance
SUBDIR+=	fonts
SUBDIR+=	games
SUBDIR+=	geography
SUBDIR+=	graphics
SUBDIR+=	ham
SUBDIR+=	inputmethod
SUBDIR+=	lang
SUBDIR+=	mail
SUBDIR+=	math
SUBDIR+=	mbone
SUBDIR+=	meta-pkgs
SUBDIR+=	misc
SUBDIR+=	multimedia
SUBDIR+=	net
SUBDIR+=	news
SUBDIR+=	parallel
SUBDIR+=	pkgtools
SUBDIR+=	print
#SUBDIR+=	regress		# regression tests must be started manually
SUBDIR+=	security
SUBDIR+=	shells
SUBDIR+=	sysutils
SUBDIR+=	textproc
SUBDIR+=	time
SUBDIR+=	wm
SUBDIR+=	www
SUBDIR+=	x11
.endif

SUBDIR+=	${USER_ADDITIONAL_PKGS}

.include "${.PARSEDIR}/mk/misc/toplevel.mk"
