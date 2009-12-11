LIB 	= minpack

LIBDIR	= ${PREFIX}/lib

all:	lib$(LIB).a

OBJ =   covar.o	dmchar.o dogleg.o dpmpar.o enorm.o errjac.o fdjac1.o	\
	fdjac2.o grdfcn.o hesfcn.o hybipt.o hybrd.o hybrd1.o hybrj.o	\
	hybrj1.o lhesfcn.o lmder.o lmder1.o lmdif.o lmdif1.o lmdipt.o	\
	lmpar.o lmstr.o lmstr1.o objfcn.o ocpipt.o qform.o qrfac.o	\
	qrsolv.o r1mpyq.o r1updt.o rwupdt.o ssqfcn.o ssqjac.o vecfcn.o	\
	vecjac.o

lib$(LIB).a:	$(OBJ)
	$(AR) cru $@ $?
	$(RANLIB) $@

install:	lib$(LIB).a
	$(BSD_INSTALL_DATA) $? $(DESTDIR)$(LIBDIR)

clean:
	rm -f *.o lib$(LIB).a
