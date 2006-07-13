# $NetBSD: bsd.patch-vars.mk,v 1.3 2006/07/13 14:02:34 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.patch.mk is included.
#
# The following variables may be set in a package Makefile:
#
#    PATCHFILES is a list of distribution patches relative to
#	${_DISTDIR} that are applied first to the package.
#
#    PATCHDIR is the location of the pkgsrc patches for the package.
#	This defaults to the "patches" subdirectory of the package
#	directory.
#
# The following variables may be set by the user:
#
#    LOCALPATCHES is the location of local patches that are maintained
#	in a directory tree reflecting the same hierarchy as the pkgsrc
#	tree, e.g., local patches for www/apache would be found in
#	${LOCALPATCHES}/www/apache.  These patches are applied after
#	the patches in ${PATCHDIR}.
#

# The default PATCHDIR is currently set in bsd.prefs.mk
#PATCHDIR?=	${.CURDIR}/patches

.if (defined(PATCHFILES) && !empty(PATCHFILES)) || \
    (defined(PATCHDIR) && exists(${PATCHDIR})) || \
    (defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH}))
USE_TOOLS+=	patch
.endif

.if (defined(PATCHDIR) && exists(${PATCHDIR})) || \
    (defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH}))
USE_TOOLS+=	digest:bootstrap
.endif

# These tools are used to output the contents of the distribution patches
# to stdout.
#
.if defined(PATCHFILES)
USE_TOOLS+=	cat
.  if !empty(PATCHFILES:M*.Z) || !empty(PATCHFILES:M*.gz)
USE_TOOLS+=	gzcat
.  endif
.  if !empty(PATCHFILES:M*.bz2)
USE_TOOLS+=	bzcat
.  endif
.endif
