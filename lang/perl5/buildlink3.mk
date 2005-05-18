# $NetBSD: buildlink3.mk,v 1.20 2005/05/18 22:42:07 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PERL5_BUILDLINK3_MK:=	${PERL5_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nperl}
BUILDLINK_PACKAGES+=	perl

.if !empty(PERL5_BUILDLINK3_MK:M+)
.  if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
USE_PERL5?=	run
PERL5_REQD+=	5.0
.  endif
USE_TOOLS+=	perl

BUILDLINK_DEPENDS.perl+=	{perl>=${PERL5_REQD},perl-thread>=${PERL5_REQD}}
BUILDLINK_RECOMMENDED.perl+=	perl>=5.8.5nb6
BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl58

.if (defined(USE_PERL5) && !empty(USE_PERL5:Mbuild)) || \
    (defined(TOOLS_DEPMETHOD.perl) && !empty(TOOLS_DEPMETHOD.perl:MBUILD_DEPENDS))
BUILDLINK_DEPMETHOD.perl?=	build
.else
TOOLS_DEPMETHOD.perl?=		DEPENDS
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
