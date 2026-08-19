# $NetBSD: common.mk,v 1.4 2026/08/19 09:22:27 jperkin Exp $
#
# This file contains the definitions that are used in all directories of
# pkgsrc -- the top-level, the categories and the packages themselves.
#
# User-settable variables:
#
# PKG_DEBUG_LEVEL
#	(See mk/help/debug.help)
#
# ULIMIT_PRECMD
#	Command that is prepended to all RUN commands.  Primarily useful for
#	setting to e.g. "ulimit -S -t 3600" to ensure no build process uses
#	over an hour of CPU time, helping to avoid infinite loop hangs.
#
# System-provided variables:
#
# RUN
#	This variable can be prepended to all shell commands that should
#	not be printed by default, but when PKGSRC_DEBUG_LEVEL is
#	non-zero. It also re-adds the error checking that has been
#	removed in 2004 to make bmake conform to POSIX.
#

.MAIN: all

.if defined(.MAKEFLAGS) && !empty(.MAKEFLAGS:M-j*)
PKG_FAIL_REASON+=	"[bsd.pkg.mk] pkgsrc does not support parallel make for the infrastructure."
PKG_FAIL_REASON+=	"[bsd.pkg.mk] Run \"${MAKE} help topic=make_jobs\" to get some parallelism."
.endif

# Include any preferences, if not already included, and common definitions
.include "../bsd.prefs.mk"

PKG_DEBUG_LEVEL?=	0
_PKG_SILENT=		@
_PKG_DEBUG=		# empty
_PKG_DEBUG_SCRIPT=	${SH}
ULIMIT_PRECMD?=		:

.if ${PKG_DEBUG_LEVEL} > 0
_PKG_SILENT=		# empty
.endif

.if ${PKG_DEBUG_LEVEL} > 1
_PKG_DEBUG=		: commands for target ${.TARGET:Q}; set -x;
_PKG_DEBUG_SCRIPT=	${SH} -x
.endif

RUN=			${_PKG_SILENT}${_PKG_DEBUG} set -e; ${ULIMIT_PRECMD};

.if make(help)
.include "../help/help.mk"
.endif
