LIB	= odepack

LIBDIR	= ${PREFIX}/lib
FORTRAN = %%FORTRAN%%
FFLAGS	= %%FOPTS%%

all:	lib$(LIB)

OBJ = adjlr.o aigbt.o ainvg.o blkdta000.o bnorm.o cdrv.o cfode.o cntnzu.o \
	decbt.o ewset.o fnorm.o intdy.o iprep.o jgroup.o lsoda.o	  \
	lsodar.o lsode.o lsodes.o lsodi.o lsoibt.o md.o mdi.o mdm.o mdp.o \
	mdu.o nnfc.o nnsc.o nntc.o nroc.o nsfc.o odrv.o pjibt.o prep.o	  \
	prepj.o	prepji.o prja.o prjs.o rchek.o roots.o slsbt.o slss.o	  \
	solbt.o solsy.o srcar.o srcma.o srcms.o srcom.o sro.o stoda.o	  \
	stode.o stodi.o vmnorm.o vnorm.o xerrwv.o xsetf.o xsetun.o

lib$(LIB):	$(OBJ)
	@$(LIBTOOL) --mode=link $(FORTRAN) $(FFLAGS) $(FOPTS) \
	-O -o lib$(LIB).la $(OBJ:.o=.lo) -rpath $(LIBDIR)

.f.o:
	@$(LIBTOOL) --mode=compile $(FORTRAN) $(FFLAGS) $(FOPTS) -c $*.f

install:	lib$(LIB)
	@$(LIBTOOL) --mode=install install -c lib$(LIB).la $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la