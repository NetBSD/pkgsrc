# $NetBSD: ext.mk,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $
# PHP wrapper, for module builds

.if !defined(PHPEXT_MK)
PHPEXT_MK=	defined

.include "../../lang/php/phpversion.mk"

.if (defined(USE_BUILDLINK3) && empty(USE_BUILDLINK3:M[nN][oO]))
.    include "${PHPPKGSRCDIR}/Makefile.module"
.endif

.endif	# PHPEXT_MK
