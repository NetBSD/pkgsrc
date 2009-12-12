LIB 	= fftpack

LIBDIR	= ${PREFIX}/lib

all:	lib$(LIB).a

OBJS =	cfftb.o cosqf1.o passb2.o radb2.o radfg.o		\
	sinqi.o cfftb1.o cosqi.o passb3.o radb3.o rfftb.o	\
	sint.o cfftf.o cost.o passb4.o radb4.o rfftb1.o		\
	sint1.o cfftf1.o costi.o passb5.o radb5.o rfftf.o	\
	sinti.o cffti.o ezfft1.o passf.o radbg.o rfftf1.o	\
	cffti1.o ezfftb.o passf2.o radf2.o rffti.o		\
	cosqb.o ezfftf.o passf3.o radf3.o rffti1.o cosqb1.o	\
	ezffti.o passf4.o radf4.o sinqb.o cosqf.o passb.o	\
	passf5.o radf5.o sinqf.o

lib$(LIB).a:	$(OBJS)
	$(AR) cru $@ $?
	$(RANLIB) $@

install:	lib$(LIB).a
	$(BSD_INSTALL_LIB) $? $(DESTDIR)$(LIBDIR)

clean:
	rm -f *.o lib$(LIB).a
