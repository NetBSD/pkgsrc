# $NetBSD: bsd.extract-vars.mk,v 1.5 2006/09/13 11:10:36 joerg Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.extract.mk is included.
#
# The following variables may be set by the package Makefile and
# specify how extraction happens:
#
#    EXTRACT_ONLY is a list of distfiles relative to ${_DISTDIR} to
#	extract and defaults to ${DISTFILES}.
#
#    EXTRACT_SUFX is the suffix for the default distfile to be
#       extracted.  The default suffix is ".tar.gz".
#


EXTRACT_ONLY?=		${DISTFILES}
EXTRACT_SUFX?=		.tar.gz

###
### Discover which tools we need based on the file extensions of the
### distfiles.
###
.if !empty(EXTRACT_ONLY:M*.tar) || \
    !empty(EXTRACT_ONLY:M*.tar.*) || \
    !empty(EXTRACT_ONLY:M*.tbz) || \
    !empty(EXTRACT_ONLY:M*.tbz2) || \
    !empty(EXTRACT_ONLY:M*.tgz) || \
    !empty(EXTRACT_ONLY:M*-tar.gz) || \
    !empty(EXTRACT_ONLY:M*_tar.gz)
.  if !empty(EXTRACT_USING:Mgtar)
USE_TOOLS+=	gtar
.  elif !empty(EXTRACT_USING:Mnbtar)
USE_TOOLS+=	tar
.  else
USE_TOOLS+=	pax
.  endif
.endif
.if !empty(EXTRACT_ONLY:M*.cpio) || \
    !empty(EXTRACT_ONLY:M*.cpio.bz2) || \
    !empty(EXTRACT_ONLY:M*.cpio.gz)
USE_TOOLS+=	pax
.endif
.if !empty(EXTRACT_ONLY:M*.bz2) || \
    !empty(EXTRACT_ONLY:M*.tbz) || \
    !empty(EXTRACT_ONLY:M*.tbz2)
USE_TOOLS+=	bzcat
.endif
.if !empty(EXTRACT_ONLY:M*.zip)
USE_TOOLS+=	unzip
.endif
.if !empty(EXTRACT_ONLY:M*.lzh) || \
    !empty(EXTRACT_ONLY:M*.lha)
USE_TOOLS+=	lha
.endif
.if !empty(EXTRACT_ONLY:M*.gz) || \
    !empty(EXTRACT_ONLY:M*.tgz) || \
    !empty(EXTRACT_ONLY:M*.Z)
USE_TOOLS+=	gzcat
.endif
.if !empty(EXTRACT_ONLY:M*.zoo)
USE_TOOLS+=	unzoo
.endif
.if !empty(EXTRACT_ONLY:M*.rar)
USE_TOOLS+=	unrar
.endif
