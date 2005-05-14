# $NetBSD: perl.mk,v 1.9 2005/05/14 21:38:18 jlam Exp $

# Create a symlink from ${TOOLS_DIR}/bin/perl to ${PERL5} when USE_PERL5
# is defined.  This ensures that when "perl" is invoked, the pkgsrc perl
# is executed on systems that also provide a perl binary.
#
.if defined(USE_PERL5) && !defined(TOOLS_IGNORE.perl)
.  if !empty(PKGPATH:Mlang/perl58)
MAKEFLAGS+=		TOOLS_IGNORE.perl=
.  else
.    include "../../lang/perl5/buildlink3.mk"
TOOLS_DEPMETHOD.perl?=	BUILD_DEPENDS
_TOOLS_DEPENDS.perl=	# empty
.    for _dep_ in ${BUILDLINK_DEPENDS.perl}
_TOOLS_DEPENDS.perl+=	${_dep_}:${BUILDLINK_PKGSRCDIR.perl}
.    endfor
.    undef _dep_
TOOLS_DEPENDS.perl?=	${_TOOLS_DEPENDS.perl}
TOOLS_CREATE+=		perl
FIND_PREFIX:=		TOOLS_PREFIX.perl=perl
.    include "../../mk/find-prefix.mk"
TOOLS_REAL_CMD.perl=	${TOOLS_PREFIX.perl}/bin/perl
PERL5=			${TOOLS_REAL_CMD.perl}
CONFIGURE_ENV+=		PERL=${PERL5:Q}
.  endif
.  if defined(TOOLS_DEPMETHOD.perl) && defined(TOOLS_DEPENDS.perl)
.    if empty(${TOOLS_DEPMETHOD.perl}:M${TOOLS_DEPENDS.perl})
${TOOLS_DEPMETHOD.perl}+=	${TOOLS_DEPENDS.perl}
.    endif
.  endif

# Define PERL5_* variables that locate the site directories for ${PERL5}.
# These variables depend on PERL5 being properly defined and existing
# on the filesystem.
#
.  include "../../lang/perl5/vars.mk"

.endif
