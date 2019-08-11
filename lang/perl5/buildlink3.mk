# $NetBSD: buildlink3.mk,v 1.64 2019/08/11 13:02:00 wiz Exp $

BUILDLINK_TREE+=	perl

.if !defined(PERL_BUILDLINK3_MK)
PERL_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"
PERL5_REQD+=			5.30.0
.for _perl5_ver_ in ${PERL5_REQD}
BUILDLINK_API_DEPENDS.perl+=	perl>=${_perl5_ver_}
.endfor
# Prevent p5-* etc. packages built for 5.30.0 to be used
# with the next incompatible version of perl:
BUILDLINK_API_DEPENDS.perl+=	perl<5.32.0

BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl5

_TOOLS_USE_PKGSRC.perl=	yes

PERL5=		${LOCALBASE}/bin/perl

pkgbase := perl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.perl:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
.endif

PERL5_OPTIONS?=		# empty
.if !empty(PERL5_OPTIONS:Mthreads)
INSTALL_TEMPLATES+=	${.CURDIR}/../../lang/perl5/files/install_threads.tmpl
.endif

#
# Perl keeps headers and odd libraries in an odd path not caught by the
# default BUILDLINK_FILES_CMD, so name them to be symlinked into
# ${BUILDLINK_DIR}.
#
.include "../../lang/perl5/vars.mk"
BUILDLINK_FILES.perl=	${PERL5_SUB_INSTALLARCHLIB}/CORE/*
BUILDLINK_RPATHDIRS.perl+=	${PERL5_SUB_INSTALLARCHLIB}/CORE
.endif # PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-perl
