# $NetBSD: buildlink3.mk,v 1.24 2005/06/24 06:43:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PERL5_BUILDLINK3_MK:=	${PERL5_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nperl}
BUILDLINK_PACKAGES+=	perl

.if !empty(PERL5_BUILDLINK3_MK:M+)
USE_TOOLS+=			perl
TOOLS_DEPENDS.perl=		# buildlink3 will handle the dependency
BUILDLINK_DEPENDS.perl+=	{perl>=${PERL5_REQD},perl-thread>=${PERL5_REQD}}
BUILDLINK_RECOMMENDED.perl+=	perl>=5.8.5nb6
BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl5

.if defined(USE_PERL5) && !empty(USE_PERL5:Mbuild)
BUILDLINK_DEPMETHOD.perl?=	build
.endif
.if defined(TOOLS_DEPMETHOD.perl) && !empty(TOOLS_DEPMETHOD.perl:MBUILD_DEPENDS)
BUILDLINK_DEPMETHOD.perl?=	build
.endif

PERL5_OPTIONS?=		# empty
.if !empty(PERL5_OPTIONS:Mthreads)
USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../lang/perl5/files/install.tmpl
.endif

.if ${PKG_INSTALLATION_TYPE} == "overwrite"
#
# Perl keeps headers and odd libraries in an odd path not caught by the
# default BUILDLINK_FILES_CMD, so name them to be symlinked into
# ${BUILDLINK_DIR}.
#
BUILDLINK_FILES.perl=							\
	${PERL5_SUB_INSTALLARCHLIB}/CORE/*				\
	${PERL5_SUB_INSTALLARCHLIB}/auto/DynaLoader/DynaLoader.a
.endif

.endif  # PERL5_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
