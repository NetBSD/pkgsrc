# $NetBSD: octave.mk,v 1.3 2005/04/01 10:15:19 adam Exp $

.include "../../mk/bsd.prefs.mk"

OCTAVE_CONFIG=	${LOCALBASE}/bin/octave-config

# OCTAVE_VARS is a list of variables to define in the make environment.
# This may be overridden in an octave add-on package Makefile.  
OCTAVE_VARS?=	LOCALVERFCNFILEDIR LOCALVEROCTFILEDIR LOCALVERARCHLIBDIR VERSION

# Set OCT_<var> to the value of <var> as returned by octave-config.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
.  if exists(${OCTAVE_CONFIG})  
.    for _var_ in ${OCTAVE_VARS}
.      if !defined(OCT_${_var_})
OCT_${_var_}!=  ${OCTAVE_CONFIG} -p ${_var_} 
.      endif 
.    endfor
.    undef _var_
.  endif 
.endif 
