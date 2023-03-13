# $NetBSD: make_env.mk,v 1.1 2023/03/13 21:11:15 wiz Exp $
# Use the variables from blas.buildlink3.mk, pulled in via cblas.
# Dependent Python packages possibly re-use the system_info logic and
# might need this in the environment.
.if ${BLAS_TYPE:U} == "accelerate.framework"
MAKE_ENV+=	NPY_BLAS_ORDER=accelerate
.else
MAKE_ENV+=	NPY_BLAS_LIBS=${BLAS_LIBS:Q} NPY_LAPACK_LIBS=${LAPACK_LIBS:Q}
MAKE_ENV+=	NPY_CBLAS_LIBS=${CBLAS_LIBS:Q}
.endif
