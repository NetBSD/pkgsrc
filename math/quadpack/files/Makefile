LIB 	= quadpack

LIBDIR	= ${PREFIX}/lib
FORTRAN = %%FORTRAN%%
FOPTS	= %%FOPTS%%

all:	lib$(LIB)

OBJ= 	dqag.o dqage.o dqagi.o dqagie.o dqagp.o dqagpe.o dqags.o	\
	dqagse.o dqawc.o dqawce.o dqawf.o dqawfe.o dqawo.o		\
	dqawoe.o dqaws.o dqawse.o dqc25c.o dqc25f.o dqc25s.o		\
	dqcheb.o dqelg.o dqk15.o dqk15i.o dqk15w.o dqk21.o		\
	dqk31.o dqk41.o dqk51.o dqk61.o dqmomo.o dqng.o dqpsrt.o	\
	dqwgtc.o dqwgtf.o dqwgts.o qag.o qage.o qagi.o qagie.o		\
	qagp.o	qagpe.o qags.o qagse.o qawc.o qawce.o qawf.o		\
	qawfe.o qawo.o qawoe.o qaws.o qawse.o qc25c.o qc25f.o		\
	qc25s.o qcheb.o qelg.o qk15.o qk15i.o qk15w.o qk21.o		\
	qk31.o qk41.o qk51.o qk61.o qmomo.o qng.o qpsrt.o		\
	qwgtc.o qwgtf.o qwgts.o

lib$(LIB):	$(OBJ)
	@$(LIBTOOL) --mode=link $(FORTRAN) $(FFLAGS) $(FOPTS) \
	-O -o lib$(LIB).la $(OBJ:.o=.lo) -rpath $(LIBDIR)

.f.o:
	@$(LIBTOOL) --mode=compile $(FORTRAN) $(FFLAGS) $(FOPTS) -c $*.f

install:	lib$(LIB)
	@$(LIBTOOL) --mode=install install -c lib$(LIB).la $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la
