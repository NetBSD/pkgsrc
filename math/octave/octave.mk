# $NetBSD: octave.mk,v 1.9 2020/04/12 21:19:32 adam Exp $

.include "../../mk/bsd.prefs.mk"

OCTAVE_CONFIG=	${PREFIX}/bin/octave-config

# OCTAVE_VARS is a list of variables to define in the make environment.
# This may be overridden in an octave add-on package Makefile.
OCTAVE_VARS?=	LOCALVERFCNFILEDIR LOCALVEROCTFILEDIR LOCALVERARCHLIBDIR VERSION

# Set OCT_<var> to the value of <var> as returned by octave-config.
.if exists(${OCTAVE_CONFIG})
.  for var in ${OCTAVE_VARS}
.    if !defined(OCT_${var})
OCT_${var}!=	${OCTAVE_CONFIG} -p ${var}
.    endif
.  endfor
.endif

# fix shebang line.
#
# REPLACE_OCTAVE	replace shebang line of specified files.
#
.if defined(REPLACE_OCTAVE)
REPLACE_INTERPRETER+=	octave
REPLACE.octave.old=	.*octave
REPLACE.octave.new=	${PREFIX}/bin/octave
REPLACE_FILES.octave=	${REPLACE_OCTAVE}
.endif # defined(REPLACE_OCTAVE)
