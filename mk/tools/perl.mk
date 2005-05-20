# $NetBSD: perl.mk,v 1.14 2005/05/20 03:00:16 jlam Exp $
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

# Substitute for PERL5_* variables in PLISTs.
PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SUB_INSTALLSITELIB}
PLIST_SUBST+=	PERL5_SITEARCH=${PERL5_SUB_INSTALLSITEARCH}
PLIST_SUBST+=	PERL5_ARCHLIB=${PERL5_SUB_INSTALLARCHLIB}
.endif
