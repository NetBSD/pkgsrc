# $NetBSD: buildlink3.mk,v 1.19 2005/05/12 21:01:16 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PERL5_BUILDLINK3_MK:=	${PERL5_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nperl}
BUILDLINK_PACKAGES+=	perl

.if !empty(PERL5_BUILDLINK3_MK:M+)
USE_PERL5?=	run
PERL5_REQD+=	5.0

BUILDLINK_DEPENDS.perl+=	{perl>=${_PERL5_REQD},perl-thread>=${_PERL5_REQD}}
BUILDLINK_RECOMMENDED.perl+=	perl>=5.8.5nb6
BUILDLINK_PKGSRCDIR.perl?=	${PERL5_PKGSRCDIR}

.if !empty(USE_PERL5:M[bB][uU][iI][lL][dD])
BUILDLINK_DEPMETHOD.perl?=	build
.endif

PERL5_OPTIONS?=	# empty
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
