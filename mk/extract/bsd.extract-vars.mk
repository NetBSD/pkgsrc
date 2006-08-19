# $NetBSD: bsd.extract-vars.mk,v 1.3 2006/08/19 20:06:57 schwarz Exp $
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

.if !empty(EXTRACT_ONLY)

###
### Discover which tools we need based on the file extensions of the
### distfiles.
###
_EXTRACT_PATTERNS=	${EXTRACT_ONLY} ${EXTRACT_SUFX}

. if !empty(_EXTRACT_PATTERNS:M*.tar) || \
     !empty(_EXTRACT_PATTERNS:M*.tar.*) || \
     !empty(_EXTRACT_PATTERNS:M*.tbz) || \
     !empty(_EXTRACT_PATTERNS:M*.tbz2) || \
     !empty(_EXTRACT_PATTERNS:M*.tgz) || \
     !empty(_EXTRACT_PATTERNS:M*-tar.gz) || \
     !empty(_EXTRACT_PATTERNS:M*_tar.gz)
.   if !empty(EXTRACT_USING:Mgtar)
USE_TOOLS+=	gtar
.   elif !empty(EXTRACT_USING:Mnbtar)
USE_TOOLS+=	tar
.   else
USE_TOOLS+=	pax
.   endif
. endif
. if !empty(_EXTRACT_PATTERNS:M*.bz2) || \
     !empty(_EXTRACT_PATTERNS:M*.tbz) || \
     !empty(_EXTRACT_PATTERNS:M*.tbz2)
USE_TOOLS+=	bzcat
. endif
. if !empty(_EXTRACT_PATTERNS:M*.zip)
USE_TOOLS+=	unzip
. endif
. if !empty(_EXTRACT_PATTERNS:M*.lzh) || \
     !empty(_EXTRACT_PATTERNS:M*.lha)
USE_TOOLS+=	lha
. endif
. if !empty(_EXTRACT_PATTERNS:M*.gz) || \
     !empty(_EXTRACT_PATTERNS:M*.tgz) || \
     !empty(_EXTRACT_PATTERNS:M*.Z)
USE_TOOLS+=	gzcat
. endif
. if !empty(_EXTRACT_PATTERNS:M*.zoo)
USE_TOOLS+=	unzoo
. endif
. if !empty(_EXTRACT_PATTERNS:M*.rar)
USE_TOOLS+=	unrar
. endif
.endif
