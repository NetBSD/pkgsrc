# $NetBSD: buildlink3.mk,v 1.48 2011/08/05 18:06:14 adam Exp $

BUILDLINK_TREE+=	perl

.if !defined(PERL_BUILDLINK3_MK)
PERL_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"
PERL5_REQD+=			5.14.0
.for _perl5_ver_ in ${PERL5_REQD}
BUILDLINK_API_DEPENDS.perl+=	perl>=${_perl5_ver_}
.endfor
# Prevent p5-* etc. packages built for 5.14.0 to be used
# with the next incompatible version of perl:
BUILDLINK_API_DEPENDS.perl+=	perl<5.16.0

BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl5

FIND_PREFIX:=	PERLDIR=perl
.include "../../mk/find-prefix.mk"
PERL5=		${PERLDIR}/bin/perl

pkgbase := perl
.include "../../mk/pkg-build-options.mk"

PERL5_OPTIONS?=		# empty
.if !empty(PERL5_OPTIONS:Mthreads)
INSTALL_TEMPLATES+=	${.CURDIR}/../../lang/perl5/files/install_threads.tmpl
.endif

.if ${PKG_INSTALLATION_TYPE} == "overwrite"
#
# Perl keeps headers and odd libraries in an odd path not caught by the
# default BUILDLINK_FILES_CMD, so name them to be symlinked into
# ${BUILDLINK_DIR}.
#
.include "../../lang/perl5/vars.mk"
BUILDLINK_FILES.perl=	${PERL5_SUB_INSTALLARCHLIB}/CORE/*
.endif
.endif # PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-perl
