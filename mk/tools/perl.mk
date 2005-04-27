# $NetBSD: perl.mk,v 1.2 2005/04/27 17:59:09 jlam Exp $

# Create a symlink from ${TOOLS_DIR}/bin/perl to ${PERL5} when USE_PERL5
# is defined.  This ensures that when "perl" is invoked, the pkgsrc perl
# is executed on systems that also provide a perl binary.
#
.if defined(USE_PERL5) && !defined(TOOLS_IGNORE.perl)
.  if !empty(PKGPATH:Mlang/perl58)
MAKEFLAGS+=		TOOLS_IGNORE.perl=
.  else
.    include "../../lang/perl5/buildlink3.mk"
TOOLS_SYMLINK+=		perl
TOOLS_REAL_CMD.perl=	${PERL5}
.    if exists(${TOOLS_REAL_CMD.perl})
PERL5=			${TOOLS_REAL_CMD.perl}
.    endif
.  endif
.endif
