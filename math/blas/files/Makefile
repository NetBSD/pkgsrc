.SUFFIXES: .so

LIB	= blas

LIBDIR	= ${PREFIX}/lib

all:	lib$(LIB).a lib$(LIB)_pic.a

OBJS = caxpy.o ccopy.o cdotc.o cdotu.o cgbmv.o cgemm.o cgemv.o cgerc.o	\
       cgeru.o chbmv.o chemm.o chemv.o cher.o cher2.o cher2k.o cherk.o	\
       chpmv.o chpr.o chpr2.o crotg.o cscal.o csrot.o csscal.o cswap.o	\
       csymm.o csyr2k.o csyrk.o ctbmv.o ctbsv.o ctpmv.o ctpsv.o		\
       ctrmm.o ctrmv.o ctrsm.o ctrsv.o dasum.o daxpy.o dcabs1.o		\
       dcopy.o ddot.o dgbmv.o dgemm.o dgemv.o dger.o dnrm2.o drot.o	\
       drotg.o drotm.o drotmg.o dsbmv.o dscal.o dsdot.o dspmv.o dspr.o	\
       dspr2.o dswap.o dsymm.o dsymv.o dsyr.o dsyr2.o dsyr2k.o dsyrk.o	\
       dtbmv.o dtbsv.o dtpmv.o dtpsv.o dtrmm.o dtrmv.o dtrsm.o dtrsv.o	\
       dzasum.o dznrm2.o icamax.o idamax.o isamax.o izamax.o lsame.o	\
       sasum.o saxpy.o scasum.o scnrm2.o scopy.o sdot.o sdsdot.o	\
       sgbmv.o sgemm.o sgemv.o sger.o snrm2.o srot.o srotg.o srotm.o	\
       srotmg.o ssbmv.o sscal.o sspmv.o sspr.o sspr2.o sswap.o ssymm.o	\
       ssymv.o ssyr.o ssyr2.o ssyr2k.o ssyrk.o stbmv.o stbsv.o stpmv.o	\
       stpsv.o strmm.o strmv.o strsm.o strsv.o xerbla.o zaxpy.o		\
       zcopy.o zdotc.o zdotu.o zdrot.o zdscal.o zgbmv.o zgemm.o		\
       zgemv.o zgerc.o zgeru.o zhbmv.o zhemm.o zhemv.o zher.o zher2.o	\
       zher2k.o zherk.o zhpmv.o zhpr.o zhpr2.o zrotg.o zscal.o zswap.o	\
       zsymm.o zsyr2k.o zsyrk.o ztbmv.o ztbsv.o ztpmv.o ztpsv.o		\
       ztrmm.o ztrmv.o ztrsm.o ztrsv.o

PIC_OBJS = caxpy.so ccopy.so cdotc.so cdotu.so cgbmv.so cgemm.so cgemv.so cgerc.so \
       cgeru.so chbmv.so chemm.so chemv.so cher.so cher2.so cher2k.so cherk.so	\
       chpmv.so chpr.so chpr2.so crotg.so cscal.so csrot.so csscal.so cswap.so	\
       csymm.so csyr2k.so csyrk.so ctbmv.so ctbsv.so ctpmv.so ctpsv.so		\
       ctrmm.so ctrmv.so ctrsm.so ctrsv.so dasum.so daxpy.so dcabs1.so		\
       dcopy.so ddot.so dgbmv.so dgemm.so dgemv.so dger.so dnrm2.so drot.so	\
       drotg.so drotm.so drotmg.so dsbmv.so dscal.so dsdot.so dspmv.so dspr.so	\
       dspr2.so dswap.so dsymm.so dsymv.so dsyr.so dsyr2.so dsyr2k.so dsyrk.so	\
       dtbmv.so dtbsv.so dtpmv.so dtpsv.so dtrmm.so dtrmv.so dtrsm.so dtrsv.so	\
       dzasum.so dznrm2.so icamax.so idamax.so isamax.so izamax.so lsame.so	\
       sasum.so saxpy.so scasum.so scnrm2.so scopy.so sdot.so sdsdot.so	\
       sgbmv.so sgemm.so sgemv.so sger.so snrm2.so srot.so srotg.so srotm.so	\
       srotmg.so ssbmv.so sscal.so sspmv.so sspr.so sspr2.so sswap.so ssymm.so	\
       ssymv.so ssyr.so ssyr2.so ssyr2k.so ssyrk.so stbmv.so stbsv.so stpmv.so	\
       stpsv.so strmm.so strmv.so strsm.so strsv.so xerbla.so zaxpy.so		\
       zcopy.so zdotc.so zdotu.so zdrot.so zdscal.so zgbmv.so zgemm.so		\
       zgemv.so zgerc.so zgeru.so zhbmv.so zhemm.so zhemv.so zher.so zher2.so	\
       zher2k.so zherk.so zhpmv.so zhpr.so zhpr2.so zrotg.so zscal.so zswap.so	\
       zsymm.so zsyr2k.so zsyrk.so ztbmv.so ztbsv.so ztpmv.so ztpsv.so		\
       ztrmm.so ztrmv.so ztrsm.so ztrsv.so

lib$(LIB).a: 	$(OBJS)
	$(AR) cru $@ $?
	$(RANLIB) $@

lib$(LIB)_pic.a:	$(PIC_OBJS)
	$(AR) cru $@ $?
	$(RANLIB) $@

install: 	lib$(LIB).a lib$(LIB)_pic.a
	$(BSD_INSTALL_DATA) $? $(LIBDIR)

clean:
	rm -f *.o lib$(LIB).a

.f.so:
	${COMPILE.f} -fPIC -o $@ $<
