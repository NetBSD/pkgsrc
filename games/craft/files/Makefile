# $NetBSD: Makefile,v 1.2 2001/12/19 10:51:19 tron Exp $
#
#---------------------------------------------------------------------
#
# The following assigns must be changed according to your system
#

GCC=	${CC}
GPP=	${CXX}

XLIB=${X11BASE}/lib
CPPFLAGS=-I${X11BASE}/include -DCRAFT_DIR=\\\"${PREFIX}/share/craft/\\\"

#
#--------------------------------------------------------------------

OBJ=	xtimer.o option_menu.o setupedit.o robot.o land.o ship.o building.o \
	dir.o object_handler.o pic.o player.o field.o ilfield.o xbm.o cmap_edit.o \
	cmap.o ppm.o compress.o table.o xmath.o io.o cry.o win.o dial.o multi_dial.o \
	menu.o xsystem.o xfile.o ppm_handler.o errorhandling.o paramreader.o pattern_match.o \
	objects.o xstring.o id_handler.o color_trans.o masks.o buttons.o lru.o scroller.o \
	selector.o cmap_selector.o getline.o file_selector.o history.o craft.o

HCC=hcc/hcc
CMP=${HCC} -compiler ${GCC} ${CPPFLAGS} ${CFLAGS} -c

LFLAGS=-Wl,-R${XLIB} -L${XLIB} -lX11 -lm -lcompat

all: craft

craft: ${OBJ}
	${GPP} ${OBJ} ${CPPFLAGS} -o craft ${LFLAGS}

%.o: %.cc
	${CMP} $*

%.o: %.hc
	${CMP} $*

${OBJ}: hcc/hcc

hcc/hcc: hcc/hcc.cc
	${GPP} ${CFLAGS} $< -o hcc/hcc

install: craft
	${BSD_INSTALL_PROGRAM} craft ${PREFIX}/bin
	${BSD_INSTALL_DATA_DIR} ${PREFIX}/share/craft
	${BSD_INSTALL_DATA_DIR} ${PREFIX}/share/doc/craft
	cp -R hcraft ${PREFIX}/share/craft
	cp -R buttons ${PREFIX}/share/craft
	cp -R html/* ${PREFIX}/share/doc/craft
	${BSD_INSTALL_DATA} .windefaults.params ${PREFIX}/share/craft
