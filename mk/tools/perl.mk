# $NetBSD: perl.mk,v 1.13 2005/05/19 03:52:23 jlam Exp $
#
# This Makefile fragment defines additional variables that are used by
# packages that use the perl tool.
#

.if defined(_USE_TOOLS) && !empty(_USE_TOOLS:Mperl)
#
# GNU configure scripts need to be told where to the real Perl
# interpreter can be found.  This value is typically hardcoded into
# Perl shebang scripts.
#
CONFIGURE_ENV+=		PERL=${TOOLS_${_TOOLS_VARNAME.perl}:Q}
#
# Define PERL5_* variables that locate the site directories for
# ${PERL5}.  These variables depend on PERL5 being properly defined
# and existing on the filesystem.  This needs to be done _after_
# ${PERL5} is fully resolved, which happens after mk/tools/replace.mk
# includes find-prefix.mk.
#
.  include "../../lang/perl5/vars.mk"
.endif
