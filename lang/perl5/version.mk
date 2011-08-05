# $NetBSD: version.mk,v 1.4 2011/08/05 18:06:14 adam Exp $
#
# Distill the PERL5_REQD list into a single value that is the highest
# version of Perl required.
#

# Default to needing Perl 5.
PERL5_REQD+=	5.0
PERL5_REQD+=	${_OPSYS_PERL_REQD}

.if !defined(_PERL5_REQD)
_PERL5_REQD?= none
.  for _version_ in ${PERL5_REQD}
.    for _pkg_ in perl-${_version_}
.      if !empty(_PERL5_REQD:Mnone)
_PERL5_PKG_SATISFIES_DEP=	yes
.        for _dep_ in ${PERL5_REQD:S/^/perl>=/}
.          if !empty(_PERL5_PKG_SATISFIES_DEP:M[yY][eE][sS])
_PERL5_PKG_SATISFIES_DEP!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${_pkg_:Q} 2>/dev/null; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.          endif
.        endfor
.        if !empty(_PERL5_PKG_SATISFIES_DEP:M[yY][eE][sS])
_PERL5_REQD=	${_version_}
.        endif
.      endif
.    endfor
.  endfor
.endif
PERL5_REQD:=	${_PERL5_REQD}
MAKEVARS+=	_PERL5_REQD
