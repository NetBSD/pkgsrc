LIB	= eispack
LIBDIR	= ${PREFIX}/lib

FORTRAN = %%FORTRAN%%
FOPTS	= %%FOPTS%%

all:	lib$(LIB)

OBJ = 	csroot.o epslon.o pythag.o bakvec.o balanc.o balbak.o bandr.o	\
	bandv.o	bisect.o bqr.o cbabk2.o	cbal.o cg.o ch.o cinvit.o	\
	combak.o comhes.o comlr.o comlr2.o comqr.o comqr2.o cortb.o	\
	corth.o	elmbak.o elmhes.o eltran.o figi.o figi2.o hqr.o	hqr2.o	\
	htrib3.o htribk.o htrid3.o htridi.o imtql1.o imtql2.o imtqlv.o	\
	invit.o minfit.o ortbak.o orthes.o ortran.o qzhes.o		\
	qzit.o qzval.o qzvec.o ratqr.o rebak.o rebakb.o reduc.o		\
	reduc2.o rg.o rgg.o rs.o rsb.o rsg.o rsgab.o rsgba.o rsm.o	\
	rsp.o rst.o rt.o svd.o tinvit.o tql1.o tql2.o tqlrat.o		\
	trbak1.o trbak3.o tred1.o tred2.o tred3.o tridib.o tsturm.o	\
	cdiv.o

lib$(LIB):	$(OBJ)
	@$(LIBTOOL) --mode=link $(FORTRAN) $(FFLAGS) $(FOPTS) \
	-O -o lib$(LIB).la $(OBJ:.o=.lo) -rpath $(LIBDIR)

.f.o:
	@$(LIBTOOL) --mode=compile $(FORTRAN) $(FFLAGS) $(FOPTS) -c $*.f

install:	lib$(LIB)
	@$(LIBTOOL) --mode=install install -c lib$(LIB).la $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la
