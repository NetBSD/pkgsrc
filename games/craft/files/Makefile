# $NetBSD: Makefile,v 1.4 2011/12/20 16:18:16 dholland Exp $
#

XLIB=${X11BASE}/lib
CPPFLAGS+=-I${X11BASE}/include -DCRAFT_DIR=\\\"${PREFIX}/share/craft/\\\"
LDFLAGS+=${COMPILER_RPATH_FLAG}${XLIB} -L${XLIB} -lX11 -lm

OBJS=	xtimer.o option_menu.o setupedit.o robot.o land.o ship.o building.o \
	dir.o object_handler.o pic.o player.o field.o ilfield.o xbm.o \
	cmap_edit.o cmap.o ppm.o compress.o table.o xmath.o io.o cry.o win.o \
	dial.o multi_dial.o menu.o xsystem.o xfile.o ppm_handler.o \
	errorhandling.o paramreader.o pattern_match.o objects.o xstring.o \
	id_handler.o color_trans.o masks.o buttons.o lru.o scroller.o \
	selector.o cmap_selector.o getline.o file_selector.o history.o craft.o

HCC=hcc/hcc
CMP=${HCC} -compiler ${CC} ${CPPFLAGS} ${CFLAGS} -c

all: craft

craft: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} ${CPPFLAGS} -o craft

.SUFFIXES: .cc .hc .o 

.cc.o:
	${CMP} $(.IMPSRC:R)

.hc.o:
	${CMP} $(.IMPSRC:R)

${OBJS}: hcc/hcc

hcc/hcc: hcc/hcc.cc
	${CXX} ${CFLAGS} hcc/hcc.cc -o hcc/hcc

install: craft
	${BSD_INSTALL_PROGRAM} craft ${DESTDIR}${PREFIX}/bin
	${BSD_INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/craft
	${BSD_INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/craft
	cp -R hcraft ${DESTDIR}${PREFIX}/share/craft
	cp -R buttons ${DESTDIR}${PREFIX}/share/craft
	cp -R html/* ${DESTDIR}${PREFIX}/share/doc/craft
	${BSD_INSTALL_DATA} .windefaults.params ${DESTDIR}${PREFIX}/share/craft
