# $NetBSD: octave.mk,v 1.6 2006/07/10 22:59:26 jlam Exp $

.include "../../mk/bsd.prefs.mk"

OCTAVE_CONFIG=	${LOCALBASE}/bin/octave-config

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
