# $NetBSD: buildlink3.mk,v 1.35 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PERL5_BUILDLINK3_MK:=	${PERL5_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nperl}
BUILDLINK_PACKAGES+=	perl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}perl

.if !empty(PERL5_BUILDLINK3_MK:M+)
.include "../../mk/bsd.prefs.mk"
USE_TOOLS+=			perl
PERL5_REQD+=			5.8.7
TOOLS_DEPENDS.perl=		# buildlink3 will handle the dependency
BUILDLINK_API_DEPENDS.perl+=	perl>=${PERL5_REQD}
BUILDLINK_PKGSRCDIR.perl?=	../../lang/perl5

PERL5_OPTIONS?=		# empty
.  if !empty(PERL5_OPTIONS:Mthreads)
INSTALL_TEMPLATES+=	${.CURDIR}/../../lang/perl5/files/install_threads.tmpl
.  endif

.  if ${PKG_INSTALLATION_TYPE} == "overwrite"
#
# Perl keeps headers and odd libraries in an odd path not caught by the
# default BUILDLINK_FILES_CMD, so name them to be symlinked into
# ${BUILDLINK_DIR}.
#
BUILDLINK_FILES.perl=							\
	${PERL5_SUB_INSTALLARCHLIB}/CORE/*				\
	${PERL5_SUB_INSTALLARCHLIB}/auto/DynaLoader/DynaLoader.a
.  endif
.endif  # PERL5_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
