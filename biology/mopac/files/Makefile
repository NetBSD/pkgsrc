#
#   Makefile for making the executable of program MOPAC
#
#
#    Valid Commands of this makefile
#
#	make		Makes the MOPAC file
#	make clean	Clean up disk to minimum config
#
#F77		=
FFLAGS	        = -O2 -w $(PKGSRC_FFLAGS)
HDRS		= SIZES
SRCS		:= $(shell ls *.f)
CSRCS           := $(shell ls *.c) 
OBJS		= $(SRCS:.f=.o) $(CSRCS:.c=.o)
SIZEDEPSRC	:= $(shell grep -l -i '      INCLUDE ' *.f; true)
SIZEDEPEND	= $(SIZEDEPSRC:.f=.o)
MOPAC		= MOPAC7
MOPACSHELL	= mopac
BINDIR		= ${PREFIX}/bin
OWNER		= root.bin

.SUFFIXES:	.o .f

.f.o:
		$(F77) $(FFLAGS) -c $<

.SUFFIXES:	.o .c

.c.o:
		$(CC) $(CFLAGS) -c $<

$(MOPAC):     	SIZES $(OBJS) 
		@echo -n "Loading $@ ... "
		$(F77) $(FFLAGS) $(OBJS) -o $@
		@echo "done"

$(SIZEDEPEND):	$(HDRS) 

###
