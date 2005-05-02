# $NetBSD: perl.mk,v 1.4 2005/05/02 04:33:53 jlam Exp $

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
TOOLS_DEPENDS.perl?=	${BUILDLINK_DEPENDS.perl}:${BUILDLINK_PKGSRCDIR.perl}
TOOLS_SYMLINK+=		perl
TOOLS_REAL_CMD.perl=	${LOCALBASE}/bin/perl
.    if exists(${TOOLS_REAL_CMD.perl})
PERL5=			${TOOLS_REAL_CMD.perl}
.    endif
.  endif
.  if defined(TOOLS_DEPMETHOD.perl) && defined(TOOLS_DEPENDS.perl)
.    if empty(${TOOLS_DEPMETHOD.perl}:M${TOOLS_DEPENDS.perl})
${TOOLS_DEPMETHOD.perl}+=	${TOOLS_DEPENDS.perl}
.    endif
.  endif
.endif
