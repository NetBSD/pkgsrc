# $NetBSD: bsd.install-vars.mk,v 1.6 2007/04/19 16:52:03 joerg Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.install.mk is included.
#
# Package-settable variables:
#
# INSTALLATION_DIRS_FROM_PLIST
#	If set to "yes", the static PLIST files of the package will
#	be used to determine which directories need to be created before
#	the "real" installation should start.
#

.if defined(USE_MTREE)
USE_TOOLS+=	mtree:bootstrap
.endif

# If MANZ is defined, then we want the final man pages to be compressed.
# If MANZ is not defined, then we want the final man pages to be
# uncompressed.
#
# We need to figure out if during installation, we need either gunzip
# or gzip to decompress or compress the installed man pages.  If a
# package sets MANCOMPRESSED to "yes" or "no", then it's an indication
# to the install code that the package itself installed the man pages
# either compressed or uncompressed.  If a package sets
# MANCOMPRESSED_IF_MANZ, then the package uses BSD-style makefiles,
# so we need to determine if the BSD-style makefile causes the man
# pages to be compressed or not.
#
.if !defined(_MANCOMPRESSED)
.  if defined(MANCOMPRESSED) && !empty(MANCOMPRESSED:M[yY][eE][sS])
_MANCOMPRESSED=		yes
.  else
_MANCOMPRESSED=		no
.  endif
.  if defined(MANCOMPRESSED_IF_MANZ) && defined(PKGMAKECONF)
_MANCOMPRESSED!=							\
	{ ${ECHO} ".include \""${PKGMAKECONF:Q}"\"";			\
	  ${ECHO} "all:";						\
	  ${ECHO} ".if defined(MANZ)";					\
	  ${ECHO} "	@${ECHO} yes";					\
	  ${ECHO} ".else";						\
	  ${ECHO} "	@${ECHO} no";					\
	  ${ECHO} ".endif";						\
	} | ${MAKE} -f - all
.  endif
.endif
_MANZ=		${MANZ:Dyes:Uno}
MAKEVARS+=	_MANCOMPRESSED _MANZ

.if !empty(_MANCOMPRESSED:M[yY][eE][sS]) && empty(_MANZ:M[yY][eE][sS])
USE_TOOLS+=	gunzip
.endif
.if empty(_MANCOMPRESSED:M[yY][eE][sS]) && !empty(_MANZ:M[yY][eE][sS])
USE_TOOLS+=	gzip
.endif
