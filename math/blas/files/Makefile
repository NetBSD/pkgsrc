LIB	= blas

LIBDIR	= ${PREFIX}/lib
FORTRAN = %%FORTRAN%%
FFLAGS	= %%FFLAGS%%

all:	lib$(LIB)

OBJ= caxpy.o ccopy.o cdotc.o cdotu.o cgbmv.o cgemm.o cgemv.o cgerc.o	\
cgeru.o chbmv.o chemm.o chemv.o cher.o cher2.o cher2k.o cherk.o		\
chpmv.o chpr.o chpr2.o crotg.o cscal.o csrot.o csscal.o cswap.o		\
csymm.o csyr2k.o csyrk.o ctbmv.o ctbsv.o ctpmv.o ctpsv.o ctrmm.o	\
ctrmv.o ctrsm.o ctrsv.o dasum.o daxpy.o dcabs1.o dcopy.o ddot.o		\
dgbmv.o dgemm.o dgemv.o dger.o dnrm2.o drot.o drotg.o drotm.o drotmg.o	\
dsbmv.o dscal.o dsdot.o dspmv.o dspr.o dspr2.o dswap.o dsymm.o dsymv.o	\
dsyr.o dsyr2.o dsyr2k.o dsyrk.o dtbmv.o dtbsv.o dtpmv.o dtpsv.o		\
dtrmm.o dtrmv.o dtrsm.o dtrsv.o dzasum.o dznrm2.o icamax.o idamax.o	\
isamax.o izamax.o lsame.o sasum.o saxpy.o scasum.o scnrm2.o scopy.o	\
sdot.o sdsdot.o sgbmv.o sgemm.o sgemv.o sger.o snrm2.o srot.o srotg.o	\
srotm.o srotmg.o ssbmv.o sscal.o sspmv.o sspr.o sspr2.o sswap.o		\
ssymm.o ssymv.o ssyr.o ssyr2.o ssyr2k.o ssyrk.o stbmv.o stbsv.o		\
stpmv.o stpsv.o strmm.o strmv.o strsm.o strsv.o xerbla.o zaxpy.o	\
zcopy.o zdotc.o zdotu.o zdrot.o zdscal.o zgbmv.o zgemm.o zgemv.o	\
zgerc.o zgeru.o zhbmv.o zhemm.o zhemv.o zher.o zher2.o zher2k.o		\
zherk.o zhpmv.o zhpr.o zhpr2.o zrotg.o zscal.o zswap.o zsymm.o		\
zsyr2k.o zsyrk.o ztbmv.o ztbsv.o ztpmv.o ztpsv.o ztrmm.o ztrmv.o	\
ztrsm.o ztrsv.o


lib$(LIB): 	$(OBJ)
	@$(LIBTOOL) --mode=link $(FORTRAN) -O -o lib$(LIB).la $(OBJ:.o=.lo) \
	-rpath $(LIBDIR)

install: 	lib$(LIB)
	@$(LIBTOOL) --mode=install install -c lib$(LIB).la $(LIBDIR)

.f.o: 
	@$(LIBTOOL) --mode=compile $(FORTRAN) $(FFLAGS) -c $*.f

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la
