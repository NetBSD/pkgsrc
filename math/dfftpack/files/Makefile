LIB = dfftpack

LIBDIR	= ${PREFIX}/lib
F77	= %%F77%%
FFLAGS	= -O3

all:	lib$(LIB)

OBJ = 	zfftb.o cfftb1.o zfftf.o cfftf1.o zffti.o cffti1.o dcosqb.o	\
	cosqb1.o dcosqf.o cosqf1.o dcosqi.o dcost.o dcosti.o ezfft1.o	\
	dzfftb.o dzfftf.o dzffti.o passb.o passb2.o passb3.o passb4.o	\
	passb5.o passf.o passf2.o passf3.o passf4.o passf5.o radb2.o	\
	radb3.o radb4.o radb5.o radbg.o radf2.o radf3.o radf4.o		\
	radf5.o radfg.o dfftb.o rfftb1.o dfftf.o rfftf1.o dffti.o	\
	rffti1.o dsinqb.o dsinqf.o dsinqi.o dsint.o sint1.o dsinti.o

lib$(LIB):	$(OBJ)
	@$(LIBTOOL) --mode=link $(F77) -O -o lib$(LIB).la $(OBJ:.o=.lo) \
	-rpath $(LIBDIR) --version-info 0:0

.f.o:
	@$(LIBTOOL) --mode=compile $(F77) $(FFLAGS) -c $*.f

install:	lib$(LIB)
	@$(LIBTOOL) --mode=install install -c lib$(LIB).la $(LIBDIR)

clean: 
	 rm -rf *.o *.lo .libs lib$(LIB).la
