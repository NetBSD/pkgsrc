LIB 	= fftpack

LIBDIR	= ${PREFIX}/lib

.if $(FC)=="f77" || $(FC)=="g77"
FOPTS=-funroll-loops -O2
.else
FOPTS=-O2
.endif

all:	lib$(LIB).la

OBJS =	cfftb.o cosqf1.o passb2.o radb2.o radfg.o		\
	sinqi.o cfftb1.o cosqi.o passb3.o radb3.o rfftb.o	\
	sint.o cfftf.o cost.o passb4.o radb4.o rfftb1.o		\
	sint1.o cfftf1.o costi.o passb5.o radb5.o rfftf.o	\
	sinti.o cffti.o ezfft1.o passf.o radbg.o rfftf1.o	\
	cffti1.o ezfftb.o passf2.o radf2.o rffti.o		\
	cosqb.o ezfftf.o passf3.o radf3.o rffti1.o cosqb1.o	\
	ezffti.o passf4.o radf4.o sinqb.o cosqf.o passb.o	\
	passf5.o radf5.o sinqf.o

lib$(LIB).la:	$(OBJS)
	$(LIBTOOL) --mode=link $(FC) $(FFLAGS) $(FOPTS) \
	-o $@ $(OBJS:.o=.lo)  -rpath $(LIBDIR) --version-info 0:0

.f.o:
	$(LIBTOOL) --mode=compile $(FC) $(FFLAGS) $(FOPTS) -c $<

install:	lib$(LIB).la
	$(LIBTOOL) --mode=install $(BSD_INSTALL_DATA) $? $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la
